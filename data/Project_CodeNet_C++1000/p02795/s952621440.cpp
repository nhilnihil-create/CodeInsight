#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<math.h>
#include<cstring>

#define ll long long
#define ull unsigned long long
#define ld long double
#define fo(i,start,end) for(ll i=start;start<end?i<end:i>end;start<end?i+=1:i-=1)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define vll vector<ll>
#define pll pair<ll,ll>
#define vc vector<char>
#define vop vector<pll>
#define vov vector<vector<ll>>
using namespace std;
const ld pi=3.14159265358979323;

const long long mod1=1e9+7;
const long long mod2=1e18;
const ll mod3=9e18;

long long power(ll  x, ll n){if(n==0)return 1;ll temp=power(x,n/2);if(n%2==0)return temp*temp;else return x*temp*temp;}

ll gcd(ll a,ll b){if(a<b) return gcd(b,a);if(b==0) return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return (a*b)/(gcd(a,b));}
void swap(int* a, int* b){int t = *a;*a = *b;*b = t;}
bool fs(ll x,ll y){return x>y;}
bool cmp(ll x ,ll y){
    return abs(x)<abs(y);
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll x,ll  y){return x>y?y:x;}

ll ow(ll a, ll b, ll mod)//a^b%mod
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ans;
}
ll sum(vll v){
    ll sm=0;
    fo(i,0,v.size())sm=sm+v[i];
    return sm;
}
bool isComposite(ll n) {
    if (n <= 3)return false;
    if (n % 2 == 0 || n % 3 == 0)return true;
    for (ll i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0)return true;
    }
    return false;
}
ll fac[1000001];
void fact(){
    fac[0]=1;
    fo(i,1,1000001){
        fac[i]=i*fac[i-1];
    }
}
int main() {
    ll h,w,n;
    cin>>h;
    cin>>w;
    cin>>n;
    if(h>w){
        if(n%h==0)cout<<(n/h)<<endl;
        else cout<<(n/h)+1<<endl;
    }
    else if(h<=w){
        if(n%w==0)cout<<(n/w)<<endl;
        else cout<<(n/w)+1<<endl;
    }
    return 0;
}
