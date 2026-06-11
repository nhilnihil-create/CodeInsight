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
	int ans = 0;
	for(int i=0;i<k;i++){
		int pre = 0;
		int now = 0;
		for(int j=i;j<(int)t.size();j+=k){
			if(j==i){
				if(t[j]=='r'){
					now += p;
					pre = 0;//p
				}else if(t[j]=='s'){
					now += r;
					pre = 1;//r
				}else{
					now += s;
					pre = 2;//s
				}
			}else{
				if(t[j]=='r'){
					if(pre==0) pre = 3;
					else{
						pre = 0;
						now += p;
					}
				}else if(t[j]=='s'){
					if(pre==1) pre = 3;
					else{
						pre = 1;
						now += r;
					}
				}else{
					if(pre==2) pre = 3;
					else{
						pre = 2;
						now += s;
					}
				}
			}
		}
		ans += now;
	}
	cout << ans << endl;
	return 0;
}