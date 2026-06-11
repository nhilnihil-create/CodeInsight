#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	reverse(s.begin(),s.end());
	vector<int> ans;
	int now = 0;
	while(now != n){
		int count = 0;
		REP(i,m){
			if(now + i == n+1) break;
			if(s[now + i] == '0') count = i;
		}
		now += count;
		if(count == 0){
			cout << -1 << endl;
			return 0;
		}else{
			ans.push_back(count);
		}
	}
	
	reverse(ans.begin(),ans.end());
	rep(i,ans.size()){
		cout << ans[i] << " ";
	}
	cout << endl;
	
    return 0;
}

