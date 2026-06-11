#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 1000000;
ll mod = INF;

ll l,r;

int main(){
    cin >> l>>r;
    if(l>0&&r-l+1>=2019){
        cout << 0<<endl;
    }else if(l==0&&r>=2019){
        cout << 0<<endl;
    }else{
        ll ans=INF;
        for(ll i=l;i<r;i++){
            for(ll j=i+1;j<=r;j++){
                ll t1=i%2019;
                ll t2=j%2019;
                ans=min(ans,t1*t2%2019);
            }
        }
        cout << ans<<endl;
    }
    return 0;
}