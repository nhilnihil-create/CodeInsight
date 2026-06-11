#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define io std::ios::sync_with_stdio(false)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const double pi=acos(-1);
const int P = 1e9+7, INF = 0x3f3f3f3f;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll n){ll r=1%P;for (a%=P; n; a=a*a%P,n>>=1)if(n&1)r=r*a%P;return r;}
const double eps=1e-5;

ll lcm(ll a,ll b)
{
   return a*b/gcd(a,b);
}
int main()
{
    int k;
    cin>>k;
    cout<<lcm(k,360)/k<<endl;
}
