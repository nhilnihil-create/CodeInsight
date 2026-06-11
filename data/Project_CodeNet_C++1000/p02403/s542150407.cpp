#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main() {
	int h, w;
	while (cin >> h >> w, h) {
		rep(i, h) {
			rep(j, w)cout << "#";
			cout << endl;
		}
		cout << endl;
	}
}