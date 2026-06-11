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
};

int main()
{
    Calc_Mod mod;

    int X,Y;
    cin >> X >> Y;
    int val;
    if((X+Y)%3!=0){
        cout << 0 << endl;
        return 0;
    }else{
        int range=(X+Y)/3;
        int ans=0;
        queue<int> q;
        rep(n,range+1){
            if(n+2*(range-n)==X&&2*n+(range-n)==Y){
                q.push(n);
            }
        }
        while(!q.empty()){
            val=q.front();
            ll up_kaijo=1;
            ll kaijo=1;
            val=min(range-val,val);
            rep(i,val){
                up_kaijo=mod.multi_mod(up_kaijo,range-i);
                kaijo=mod.multi_mod(kaijo,val-i);
            }
            ans=mod.plus_mod(ans,mod.div_mod(up_kaijo,kaijo));
            q.pop();
        }
        cout << ans << endl;
    }
}