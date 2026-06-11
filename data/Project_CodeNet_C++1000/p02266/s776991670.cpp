#include <cstdio>
#include <cstring>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

int n;
char s[20001];
int a[20001];
int x[20001];
int y[20001];
int b[20001];

int main(){
	scanf("%s", s);
	n = strlen(s);

	rep(i, n){
		a[i + 1] = a[i] + (s[i] == '\\' ? -1 : s[i] == '/');
	}
	rep(i, n){
		x[i + 1] = max(x[i], a[i + 1]);
	}
	y[n] = a[n];
	for(int i = n - 1; i >= 0; --i){
		y[i] = max(y[i + 1], a[i]);
	}
	rep(i, n + 1){
		b[i] = min(x[i], y[i]);
	}

	int s = 0;
	rep(i, n){
		s += (b[i] - a[i]) + (b[i + 1] - a[i + 1]);
	}
	printf("%d\n", s / 2);
	s = 0;
	vector<int> v;
	rep(i, n){
		s += (b[i] - a[i]) + (b[i + 1] - a[i + 1]);
		if(b[i + 1] == a[i + 1] && s != 0){
			v.push_back(s / 2);
			s = 0;
		}
	}
	printf("%d", (int)v.size());
	for(int w: v){
		printf(" %d", w);
	}
	putchar('\n');
	return 0;
}