#include <cstdio>
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// ----- very fast input/output ----- //
int read_int() {
	char ch = getchar_unlocked();
	int res = 0;
	while('0' <= ch && ch <= '9') {
		res = res * 10 + ch - '0';
		ch = getchar_unlocked();
	}
	return res;
}
void print_str(const char* str) {
	while(*str != '\0') {
		putchar_unlocked(*str);
		++str;
	}
}
char buf[1024];
void print_int(int x) {
	if(x < 0) {
		putchar_unlocked('-');
		x *= -1;
	}
	int ptr = 0, g;
	do {
		g = x / 10;
		buf[ptr++] = x - g * 10;
		x = g;
	} while(x > 0);
	while(ptr--) {
		putchar_unlocked(buf[ptr] + '0');
	}
}
// ----- main part ----- //
int N, sep[102400], dst[102400], depth[102400], par[102400];
int inputs[307200];
void find_depth(int pos) {
	for(int i = sep[pos]; i < sep[pos + 1]; ++i) {
		depth[dst[i]] = depth[pos] + 1;
		find_depth(dst[i]);
	}
}
int main() {
	// #1. read input
	N = read_int();
	for(int i = 0; i < 3 * N - 1; ++i) {
		inputs[i] = read_int();
	}
	// #2. construct tree
	int curpos = 0;
	for(int i = 0; i < N; ++i) {
		sep[inputs[curpos] + 1] = inputs[curpos + 1];
		curpos += inputs[curpos + 1] + 2;
	}
	for(int i = 0; i < N; ++i) {
		sep[i + 1] += sep[i];
	}
	curpos = 0;
	int root = 0;
	for(int i = 0; i < N; ++i) {
		int id = inputs[curpos];
		for(int j = sep[id]; j < sep[id + 1]; ++j) {
			dst[j] = inputs[curpos + j - sep[id] + 2];
			par[dst[j]] = id;
			root ^= dst[j];
		}
		root ^= i;
		curpos += inputs[curpos + 1] + 2;
	}
	par[root] = -1;
	find_depth(root);
	// step #3. print the answer
	for(int i = 0; i < root; ++i) {
		print_str("node ");
		print_int(i);
		print_str(": parent = ");
		print_int(par[i]);
		print_str(", depth = ");
		print_int(depth[i]);
		if(sep[i] == sep[i + 1]) {
			print_str(", leaf, []\n");
		}
		else {
			print_str(", internal node, [");
			print_int(dst[sep[i]]);
			for(int j = sep[i] + 1; j < sep[i + 1]; ++j) {
				putchar_unlocked(',');
				putchar_unlocked(' ');
				print_int(dst[j]);
			}
			putchar_unlocked(']');
			putchar_unlocked('\n');
		}
	}
	print_str("node ");
	print_int(root);
	print_str(": parent = ");
	print_int(par[root]);
	if(sep[root] == sep[root + 1]) {
		print_str(", depth = 0, root, []\n");
	}
	else {
		print_str(", depth = 0, root, [");
		print_int(dst[sep[root]]);
		for(int i = sep[root] + 1; i < sep[root + 1]; ++i) {
			putchar_unlocked(',');
			putchar_unlocked(' ');
			print_int(dst[i]);
		}
		putchar_unlocked(']');
		putchar_unlocked('\n');
	}
	for(int i = root + 1; i < N; ++i) {
		print_str("node ");
		print_int(i);
		print_str(": parent = ");
		print_int(par[i]);
		print_str(", depth = ");
		print_int(depth[i]);
		if(sep[i] == sep[i + 1]) {
			print_str(", leaf, []\n");
		}
		else {
			print_str(", internal node, [");
			print_int(dst[sep[i]]);
			for(int j = sep[i] + 1; j < sep[i + 1]; ++j) {
				putchar_unlocked(',');
				putchar_unlocked(' ');
				print_int(dst[j]);
			}
			putchar_unlocked(']');
			putchar_unlocked('\n');
		}
	}
	return 0;
}
