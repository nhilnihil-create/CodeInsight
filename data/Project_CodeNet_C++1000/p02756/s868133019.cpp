#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100005;

char str[N];

int main() {
	scanf("%s", str);
	deque<char> d;
	for(int i = 0; str[i]; i++) {
		d.push_back(str[i]);
	}

	bool inv = false;
	int q;
	scanf("%d", &q);
	while(q--) {
		int t;
		scanf("%d", &t);
		if(t == 1) inv ^= 1;
		else {
			char c;
			scanf(" %d %c", &t, &c);
			t--;
			t ^= inv;
			if(t == 0) d.push_front(c);
			else d.push_back(c);
		}
	}

	if(!inv) {
		while(!d.empty()) {
			printf("%c", d.front());
			d.pop_front();
		}
	}
	else {
		while(!d.empty()) {
			printf("%c", d.back());
			d.pop_back();
		}
	}
	printf("\n");
}
