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

ll n,d;
cin>>n>>d;

vll v[n];
f(i,0,n){
    f(j,0,d)
    {
        ll x;
        cin>>x;
        v[i].pb(x);
    }
}

ll ans = 0;
f(i,0,n){
    f(j,i+1,n)
    {
        ll temp = 0;
        f(k,0,d)
        {
            temp += pow((v[i][k]-v[j][k]),2);
        }
        ll tmp = sqrt(temp);
        if(tmp*tmp == temp)
        ans++;
    }
}

cout<<ans<<endl;




}
