#include<bits/stdc++.h>
using namespace std;

#define ll long long
int pre[200001], post[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k, c; string s;
	cin >> n >> k >> c >> s;
	for(int i=0,id=0;i<n;i++) {
		if(s[i] == 'o') {
			pre[id++] = i;
			i += c;
		}
	}

	for(int i=n-1,id=k-1;i>-1 && id > -1;i--) {
		if(s[i] == 'o') {
			post[id--] = i;
			i -= c;
		}
	}

	for(int i=0;i<k;i++) {
		if(pre[i]==post[i]) {
			cout << pre[i]+1 << '\n';
		}
	}
}