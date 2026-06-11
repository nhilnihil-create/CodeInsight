#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
typedef vector<pair<ll,ll> > Q;
typedef pair<int,int> P;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
const ll inf=1e9+7;
ll gcd(ll a, ll b) { return (b ? gcd(b, a % b) : a); }
ll lcm(ll a, ll b) { return a / (gcd(a, b)) * b; }

int main(){
    ll n,k;
    cin>>n>>k;
    ll a[2000];
    rep(i,0,n) cin>>a[i];

    ll inside=0;
    rep(i,0,n-1)
    rep(j,i+1,n){
      if(a[i]>a[j]) inside++;
    }

    ll outside=0;
    rep(i,0,n)
    rep(j,0,n){
      if(a[i]>a[j]) outside++;
    }

    //ll ans=(inside*k)%inf;

    //ans+=((k*(k-1)/2)%inf)*(outside);

    ll ans=inside*k;
    ans%=inf;

    ans+=outside*((k*(k-1)/2)%inf);
    ans%=inf;
    cout<<ans<<endl;

    return 0;
    //cout<<ans%inf<<endl;
    //cout<<inside<<' '<<outside;
}
