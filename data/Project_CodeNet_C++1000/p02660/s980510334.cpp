 #include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;

 #define rep(i, a, b) for (int i=a; i<(b); i++)
    
 #define sz(x) (int)(x).size()
 #define mp make_pair
 #define pb push_back
 #define f first
 #define s second
 #define lb lower_bound
 #define ub upper_bound
 #define all(x) x.begin(), x.end()
 

 #define trav(container, it) for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
 
 #define PI 3.14159265358979323846264338327950L
const int MOD = 1000000007;
const char nl = '\n';

ll primef(ll n)
{
    vl v;
    ll count=0;
    ll temp = n;
    ll res=0;
    for(ll i=2;i*i<=n;++i)
    {
        count=0;
        if(temp%i == 0)
        {
            while(temp%i == 0)
            {
                temp/=i;
                ++count;
            }          
        //}
        for(int j=1;j<=count;++j)
        {
            res++;
            count-=j;            
        }
    }  
    }
    if(temp>1) res++;
    return res;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;cin>>n;


    ll res = primef(n);

    cout<<res;
}
