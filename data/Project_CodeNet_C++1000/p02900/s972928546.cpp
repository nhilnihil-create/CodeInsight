
#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
ll GCD(ll x,ll y){
    if(x%y==0)return y;
    return GCD(y,x%y);
}
ll LCM(int a, int b){
    return a*b/GCD(a,b);
}

int main(void){
    ll a,b;
    cin>>a>>b;

    ll g=gcd(a,b);

    ll ans=1;
    for(ll i=2;i*i<=g;i++){
        if(g%i==0){
            ans++;
            while(g%i==0){
                g/=i;
            }
        }
    }
    if(g !=1)ans++;

    cout<<ans<<endl;
    return 0;
}

