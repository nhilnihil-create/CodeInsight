#include <bits/stdc++.h>
#include <string>
#include <cmath>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
 
#define all(v) v.begin(),v.end()
#define test() int t;cin>>t;while(t--) 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9+7;

int main()
{   
    fastio
    ll n, count = 0, d;
    cin>>n>>d;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin>>x>>y;
        if(x*x + y*y <= d*d)count++;
    }
    cout<<count<<endl;    
}