#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;

signed main(){
	ll m,d; cin>>m>>d;
	ll ans=0;
	rep(i,1,m+1){
		for(int j=2;j*j<=i;j++){
			if(i%j==0 && i/j>1 && j/10==0 && (i/j)/10==0){
				if(j==(i/j)){
					if(j*10+(i/j)<=d)ans++;
				}
				else{
					if(j*10+(i/j)<=d)ans++;
					if((i/j)*10+j<=d)ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}