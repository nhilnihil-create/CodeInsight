#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
using namespace std;
ll binpow(ll x,ll y)/* (x^y)%p in O(log y) */{ll res=1;while (y > 0){if(y&1)res=(res*x);y = y>>1;x=(x*x);}return res;}
ull binpowmod(ull x,ull y,ull p)/* (x^y)%p in O(log y) */{ull res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
ll mod_inverse(ll n,ll p)/* Returns n^(-1) mod p */{return binpowmod(n,p-2,p);}
ull gcd(ull x,ull y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
bool comp(pair<int,int> x,pair<int,int> y)
{
    if(x.first<y.first)
        return true;
    else if(x.first==y.first)
        return x.second>y.second;
    else
        return false;
}
bool comp_pairs_by_s(pair<ll,ll> &x ,pair<ll,ll> &y)
{
    return x.second<y.second;
}
bool isPowerOfTwo (ll x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
}

class cmp      //comparator for priority_queue 
{               //declaration: priority_queue<int,vector<int>,cmp>
public:         
    bool operator()(pair<int,int> A,pair<int,int> B)
    {
        if(abs(A.first-A.second)==abs(B.first-B.second))
            return A.first>B.first;
        return abs(A.first-A.second)<abs(B.first-B.second);
    }
};
// int prime[100005]={0};
// void sieve(void)
// {
//  int i,j;
//  for(i=0;i<100005;i++)
//         prime[i]=1;
//  prime[0]=0,prime[1]=0;
//  for(i=2;i<=sqrt(100005);i++){
//      if(prime[i]){
//          for(j=i*i;j<100005;j+=i){
//              prime[j]=0;
//          }
//      }
//  }
    
// }
void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
vector<int> g[200001];
void solve()
{   
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(ll i=k;i<=n;i++){
        ll minsum=(i-1)*i/2;
        ll maxsum=i*(2*n-i+1)/2;
        // if(i==k)
        //     cout<<maxsum-minsum;
        ans=(ans+maxsum-minsum+1)%mod;
        //cout<<ans<<'\n';
        //cout<<i<<' '<<ans<<'\n';
    }
    cout<<ans+1;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
