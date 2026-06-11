#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll gcd(ll x,ll y){
    if(x%y==0)return y;
    return gcd(y,x%y);
}
ll LCM(int a, int b){
    return a*b/gcd(a,b);
}
int counterBit(int x){
    if(x==0)return 0;
    return counterBit(x>>1)+(x&1);
}
int main(void)
{
    int n;
    cin>>n;
    vector<int> a(n);
    int g[20][20];
    rep(i,0,20){rep(j,0,20)g[i][j]=-1;}

    rep(i,0,n){
        cin>>a[i];
        rep(j,0,a[i]){
            int x,y;
            cin>>x>>y;
            x--;
            g[i][x]=y;
        }
    }

    int ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        vector<int> honest(n);
        // 正直者を仮定する
        rep(i,0,n){          
            if((1<<i)&bit){ // iの人の証言が正しい時
                honest[i]=1;
            }
        }
        // 仮定と矛盾がないか検証する
        bool ok=true;
        rep(j,0,n){
            if(honest[j]){
                rep(k,0,n){
                    if(g[j][k]==-1)continue; // 証言していない場合
                    // 証言と矛盾があった場合,この組の正直者はあり得ない
                    if(g[j][k] !=honest[k]) ok=false;
                }
            }
        }
        if(ok)ans=max(ans,counterBit(bit));
    }
    cout<<ans<<endl;
    return 0;
}