#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const ll INF=1e18;


int main() {
	int	n,rsum = 0,ans =0;
	string s;
	cin >> n >> s;
	rep(i,n){
		if(s[i] == 'R') rsum++;
	}
	rep(i,rsum){
		if(s[i] == 'W') ans++;
	}
	cout << ans <<endl;
}