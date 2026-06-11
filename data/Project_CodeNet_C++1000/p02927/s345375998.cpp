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
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	int n,d; cin>>n>>d;
	int ans=0;
	rep(i,1,n+1){
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				int k=i/j;
				if(j/10==0 && k/10==0){
					//cout<<i<<" "<<j<<" "<<i/j<<endl;
					if((k*10+j)<=d)ans++;
					if((j*10+k)<=d)ans++;
					if(j==k && k*10+k<=d)--ans;
				}
			}
		}
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}