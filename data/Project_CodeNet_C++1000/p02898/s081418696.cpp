#include <bits/stdc++.h>
#include<numeric>
#include<cstdlib>


 
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define v vector<long long int> 
#define vv vector< int> 
#define gcd(m,n) __gcd(m,n)

#define vp vector<pair<long long int ,long long int>>
#define pb push_back
#define mp make_pair
#define pp pop_back
#define iter vector<int>::iterator
#define pa pair<long long int ,long long int> 
#define f(i,n) for(int i=0;i<n;i++)

#define fe(d,e) for(auto d:e)
#define mod 1000000007
#define F first
#define S second
#define sett set<long long int>
#define um unordered_map<ll,ll>
#define ordered_set tree<pa, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// ll mul(ll a,ll b)

using namespace std;
ll power(ll x, unsigned long long  y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y/2; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
} 
int fib(int n) { 
  double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5)); 
} 
ll max_subarray_sum(v arr)
{
    ll max_till = -10000000000000;
    ll  val =0;
    f(i,arr.size())
    {
        val+=arr[i];
        max_till = max(max_till,val);
        if (val <0)
        val=0;
    }
    // cout<<"max-till"<<max_till;
    return max_till;


}

void print_vec(v arr){
    f(i,arr.size())
    cout<<arr[i]<<" ";
    cout<<endl;
}


void solve()
{   
   ll n,k;
   cin>>n>>k;
   v arr(n);
   for(auto &x:arr)cin>>x;
   ll ans=0;
   f(i,n){
       if (arr[i]>=k)ans+=1;
   }
   cout<<ans<<endl;
    }











    



int main()
{   fastio;

    
	ll t;
    // ll n,m; 
    // cin>>t;
    t=1;
    f(_,t){
        solve();
    }

     
    



}

    
