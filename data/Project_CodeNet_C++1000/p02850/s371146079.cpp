#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
using namespace std;
ll binpow(ll x,ll y)/* (x^y)%p in O(log y) */{ll res=1;while (y > 0){if(y&1)res=(res*x);y = y>>1;x=(x*x);}return res;}
ll binpowmod(ll x,ll y,ll p)/* (x^y)%p in O(log y) */{ull res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
ll mod_inverse(ll n,ll p)/* Returns n^(-1) mod p */{return binpowmod(n,p-2,p);}
ll gcd(ll x,ll y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
bool comp(pair<int,int> x,pair<int,int> y)
{
    return x.first<y.first;
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
// int prime[10000007]={0};
// void sieve(void)
// {
//  int i,j;
//  for(i=0;i<10000007;i++)
//         prime[i]=1;
//  prime[0]=0,prime[1]=0;
//  for(i=2;i<=sqrt(10000007);i++){
//      if(prime[i]==i){
//          for(j=i*i;j<10000007;j+=i){
//             if(!prime[j])
//                 prime[j]=0;
//          }
//      }
//  }
    
// }
void swap(ll &x,ll &y){
    int temp=x;
    x=y;
    y=temp;
}
  
unsigned int onesComplement(unsigned int n) 
{ 
   // Find number of bits in the given integer 
   int number_of_bits = floor(log2(n))+1; 
  
   // XOR the given integer with poe(2,  
   // number_of_bits-1 and print the result  
   return ((1 << number_of_bits) - 1) ^ n; 
}
vector<pair<int,int>> g[100001];
vector<int> edge(100001);
void dfs(int node,int p=0,int color=-1){
    int cc=1;
    for(pair<int,int> to: g[node]){
        if(to.first == p) continue;
        if(cc == color) cc++;
        edge[to.second]=cc;
        dfs(to.first,node,cc);
        cc++;
    }
}

void solve()
{   
    int n;
    cin>>n;
    for(int i=1;i<=n-1;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    int ans=INT_MIN;
    for(int i=1;i<=n;++i){
        int size=g[i].size();
        ans=max(ans,size);
    }
    cout<<ans<<'\n';
    dfs(1);
    for(int i=1;i<=n;++i){
        if(edge[i])
            cout<<edge[i]<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}   
