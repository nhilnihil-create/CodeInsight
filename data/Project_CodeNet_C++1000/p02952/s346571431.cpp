#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define dd double
#define ld long double
#define f(i,a,b) for(ll i = a; i < b; i++)
#define fr(i,a,b) for(ll i = b;i>=a;i--)
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define vpll vector< pii >
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define Sort(v) sort(v.begin(), v.end(), sortbysec)
#define MEM(a, b) memset(a, (b), sizeof(a))

ll power(ll x, ll y, ll p)  
{  
    ll res = 1;      
    x = x % p; 
                
    while (y > 0)  
    {   
        if (y & 1)  
            res = (res*x) % p;   
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
}  

 

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll n;
cin>>n;

ll st = 1;
ll ans = 0;
while(1)
{
    if(st > n)
    break;
   if(st*10 <= n)
   {
       if(st == 1)
       ans += 9;
       else
       ans += st*9;

       st *= 100;
   }
   else
   {
       ans += n-st+1;
       st *= 100;
   }
   
}

cout<<ans<<endl;




}
