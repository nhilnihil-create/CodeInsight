#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 998244353
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

vector<ll> divisor(ll n,vector<ll> &ret){//約数全列挙
    
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ret.push_back(i);
            if(i*i!=n) ret.push_back(n/i);
        }
    }
    sort(ret.begin(),ret.end());//昇順に並べる
    return ret;
}

int main(){
	ll n;cin>>n;
	
	vector<ll> ret1,ret2,per1;
	
	divisor(n,ret1);
	divisor(n-1,ret2);
	ll ans=ret2.size()-1;//1は除く

	rep(i,ret1.size()){//割るパターンはこれだけ
		ll ins=n;
		if(ret1[i]==1) continue;
		while(ins%ret1[i]==0){
			ins/=ret1[i];
		}
		ins%=ret1[i];

		if(ins==1){
			ans++;
		}
	}

	cout<<ans<<endl;
	return 0;
}