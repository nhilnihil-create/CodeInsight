#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 107
int p[MAXN];
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int x,n; cin >> x >> n;
	for(int i=0; i<n; i++) cin >> p[i];
	sort(p,p+n);
	int ii=lower_bound(p,p+n,x)-p;
	int xx=x, ox=x;
	for(int i=ii; i<n; i++) {
		if(p[i]==x) {
			x++;
		} else {
			break;
		}
	}
	for(int i=ii; i>=0; i--) {
		if(p[i]==xx) {
			xx--;
		} else {
			break;
		}
	}
	if(x-ox<ox-xx) {
		cout << x << '\n';
	} else {
		cout << xx << '\n';
	}
}
