#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
	cout << fixed << setprecision(10);
	int n,k,r,s,p;
	cin >> n >> k >> r >> s >> p;
	string t;
	cin >> t;
	int  ans = 0;
	rep(i,k){
		int pre = -1;
		for(int j = i ; j < t.size(); j += k){
			if(t[j] == 'r'){
				if(pre == 0){
					pre = -1;
				}else{
					pre = 0;
					ans += p;
				}
			}else if(t[j] == 's'){
				if(pre == 1){
					pre = -1;
				}else{
					pre = 1;
					ans += r;
				} 
			}else{
				if(pre == 2){
					pre = -1;
				}else{
					pre = 2;
					ans += s;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}