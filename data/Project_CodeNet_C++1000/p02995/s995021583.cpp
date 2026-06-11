#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

ll gcd(ll a,ll b){
	if (a%b==0) return(b);
	else return(gcd(b,a%b));
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;

    ll ans=b-(b/c+b/d-b/lcm(c,d));
    ans-=a-1-((a-1)/c+(a-1)/d-(a-1)/lcm(c,d));

    cout<<ans<<endl;
}