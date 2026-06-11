#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
using namespace std;
using ll=long long;
using ld=long double;
typedef pair<int,int> P;

class Calc_Mod{//mod演算用クラス
    public:
        unsigned int mod=1000000007;
        ll plus_mod(ll a,ll b){
            return (a+b)%mod;
        }
        ll minus_mod(ll a,ll b){
            return (a-b)%mod;
        }
        ll multi_mod(ll a,ll b){
            return a*b%mod;
        }
        ll LSM(ll a,int b){//a^b%mod
            queue<int> q;
            while(b>=1){
                q.push(b%2);
                b/=2;
            }
            ll ans=1;
            while(!q.empty()){
                if(q.front()==1){
                    ans=multi_mod(ans,a);
                }
                a=multi_mod(a,a);
                q.pop();
            }
            return ans;
        }
        ll div_mod(ll a,ll b){// a/b
            return multi_mod(a,LSM(b,mod-2));
        }

        ll combi(ll a,ll b){
            ll ans=1;
            ll kaijo=1;
            rep(i,b){
                ans=multi_mod(ans,a-i);
                kaijo=multi_mod(kaijo,b-i);
            }
            ans=div_mod(ans,kaijo);
            return ans;
        }
};

int main()
{
    ll N;
    int a,b;
    cin >> N >> a >> b;

    int ans=0;
    Calc_Mod mod;
    ans=mod.LSM(2,N)-1;
    P no_use;
    no_use.first=mod.combi(N,a);
    no_use.second=mod.combi(N,b);
    ans=mod.minus_mod(ans,no_use.first);
    ans=mod.minus_mod(ans,no_use.second);
    if(ans<0){
        ans+=mod.mod;
    }
    cout << ans << endl;


}