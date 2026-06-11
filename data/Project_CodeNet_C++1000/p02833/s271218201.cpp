#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
const int maxn = 1000000;
ll mod = INF;

ll n;

int main(){
    cin >> n;

    if(n%2==1){
        cout << 0<<endl;
    }else{
        while(n%10!=0)n-=2;
        ll ans=0;
        ll t=10;
        while(t<=n){
            ans+=n/t;
            t=t*5;
        }
        cout << ans<<endl;
    }
    return 0;
}