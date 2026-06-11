#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	string s;
	cin >> s;
	string now = s.substr(0,1);
	int ans = 1;
	int n = s.size();
	REP(i,n-1){
		if(i == n-1){
			if(s.substr(i,1) == now){
				now = s.substr(i,2);
				i++;
			}else{
				now = s.substr(i,1);
				ans++;
			}
		}else{
			if(s.substr(i,1) == now){
				now = s.substr(i,2);
				ans++;
				i++;
			}else{
				now = s.substr(i,1);
				ans++;
			}
		}
	}
	cout << ans << endl;
    return 0;
}

