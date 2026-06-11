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
    int n;
    string str;
    cin>>n;
    cin>>str;
    int addr, addw;
    vi pfx_sumw(n+1), pfx_sumr(n+1);
    for (int i = 0; i < n; i++)
    {
        addr=0;
        addw=0;
        if(str[i]=='R')addr = 1;
        else addw = 1;
        pfx_sumr[i+1]=addr+pfx_sumr[i];
        pfx_sumw[i+1]=addw+pfx_sumw[i];
    }
    int mn = n;
    for (int i = 0; i <=n; i++)
    {
        mn=min(mn, max(pfx_sumw[i], pfx_sumr[n]-pfx_sumr[i]));
    }
    cout<<mn<<endl;
}