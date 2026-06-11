// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
typedef long long int ll;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
#define MOD 1000000007
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);  
//*s.find_by_order(p)   returns the value of pth largest starting from 0 
//s.order_of_key(p)   returns no. of items that are strictly < p 
//string bin = bitset<64>(m).to_string();     convert decimal m to binary 
#define MAXN   1000005
int spf[MAXN]; 
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}
int main()
{
      fast;ll t;t=1;
      while(t--)
      {
            sieve();
            ll n,i,a,j,g;
            cin>>n;
            ll k=0;
            map<ll,ll>m;
            for(i=0;i<n;i++)
            {
                  cin>>a;
                  if(i==0){g=a;}
                  else{g=__gcd(g,a);}
                  vector<int>v=getFactorization(a);
                  v.pb(1);
                  sort(v.begin(),v.end());
                  for(j=1;j<v.size();j++)
                  {
                        if(v[j]!=v[j-1]){
                              if(m[v[j]]==1){k=1;}
                              m[v[j]]++;
                              //cout<<v[j]<<" ";
                        }
                  }
            }
            if(k==0){cout<<"pairwise coprime\n";}
            else if(g==1){cout<<"setwise coprime\n";}
            else{cout<<"not coprime\n";}
      }
}