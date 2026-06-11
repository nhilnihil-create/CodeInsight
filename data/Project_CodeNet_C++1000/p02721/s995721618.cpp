#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef   long long int ll;
typedef unsigned long long int sll;
typedef  double ld;
#define A 1000000007ll
#define B 998244353ll
#define C 1000000000000000000ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define ve vector
#define br break
#define PI 3.1415926535

int main() 
{
    FAST;
    ll n,k,c;
    string s;
    cin>>n>>k>>c>>s;
    ve<ll> v1,v2;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='o')
        {
            v1.pb(i);
            i=i+c;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='o')
        {
            v2.pb(i);
            i=i-c;
        }
    }
    reverse(v2.begin(),v2.end());
    if(v1.size()==k && v2.size()==k)
    {
        for(int i=0;i<k;i++)
            if(v1[i]==v2[i])
                cout<<v1[i]+1<<'\n';
    }
    return 0;
}