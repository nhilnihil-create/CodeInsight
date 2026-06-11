#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
using namespace std;
ll binpow(ll x,ll y)/* (x^y)%p in O(log y) */{ll res=1;while (y > 0){if(y&1)res=(res*x);y = y>>1;x=(x*x);}return res;}
ll binpowmod(ll x,ll y,ll p)/* (x^y)%p in O(log y) */{ll res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
ll mod_inverse(ll n,ll p)/* Returns n^(-1) mod p */{return binpowmod(n,p-2,p);}
ull gcd(ull x,ull y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
bool comp(pair<ll,ll> x,pair<ll,ll> y)
{
    return x.first>y.first;
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

void solve()
{   
    int n;
    cin>>n;
    vector< pair<ll,ll> > p(n);
    for(int i=1;i<=n;i++){
        p[i-1].first=i;
        cin>>p[i-1].second;
    }
    sort(p.begin(),p.end(),comp);
    vector<ll> v1(n);
    vector<ll> v2(n);
    for(int i=0;i<n;i++){
        //cout<<p[i].first<<' '<<p[i].second<<'\n';
        v1[i]=p[i].first-p[i].second;
        v2[i]=p[i].first+p[i].second;
    }
    sort(v2.begin(),v2.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        auto up=upper_bound(v2.begin(),v2.end(),v1[i]);
        auto low=lower_bound(v2.begin(),v2.end(),v1[i]);
        up--;
        if(low==v2.end()) continue;
        if(*low!=v1[i] || *up!=v1[i]) continue;

        ans+=(up-low+1);
        if(p[i].first==p[i].second)
            ans--;
    }
    cout<<ans;
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
