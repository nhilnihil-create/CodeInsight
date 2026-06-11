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
vector<ll> ar[10];
void solve()
{   
    int n;
    cin>>n;
    if(n<=9)
        cout<<n;
    else
    {
        vector<pair<int,int>> index(10,{0,1});
        for(int i=1;i<=9;++i)
            ar[i].push_back(i);
        n-=9;
        while(1){
            for(int i=1;i<=9;++i){
                int j=index[i].first;
                int end=index[i].second;
                for(;j<end;++j){
                    for(int digit=max(ar[i][j]%10-1,0LL);digit<=min(9LL,ar[i][j]%10+1);++digit){
                        ar[i].push_back(ar[i][j]*10+digit);
                        //cout<<ar[i][j]*10+digit<<'\n';
                        --n;
                        if(n==0){
                            cout<<ar[i].back();
                            return;
                        }
                    }
                }
                index[i].first=end;
                index[i].second=ar[i].size();

            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}   
