#include <bits/stdc++.h>
using namespace std;
#define INF 1e9+7
typedef long long int ll;
const int maxn = 100000;
ll mod = INF;
ll a,b,c,d;
ll ans=0;

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main(){
    
    cin >> a>>b>>c>>d;
    ll lcm=c*d/gcd(c,d);
    ans=b-a+1;
    ans-=(b/c-(a-1)/c)+(b/d-(a-1)/d)-(b/lcm-(a-1)/lcm);

    cout << ans<<endl;

    return 0;
}