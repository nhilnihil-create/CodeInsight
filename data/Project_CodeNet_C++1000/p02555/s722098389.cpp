#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
#define mp make_pair
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<int>>;
#define MAX 1000000007

class Calc_Mod{//calculate mod
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
        ll combi(ll a,ll b){//aCb
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
    int s;
    cin >> s;
    ll ans=0;
    Calc_Mod cal;
    if(s<3){
        cout << 0 << endl;
    }

    else{
        s-=3;
        int i=0;
        while(s>=0){
            ans=cal.plus_mod(ans,cal.combi(s+i,i));
            ++i;s-=3;
        }
        cout << ans << endl;
    }


    
}