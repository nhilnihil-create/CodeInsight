#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;   
#define ll long long
#define ull unsigned long long
// #define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> 
ll mod=1e9+7;
#define PI 3.1415926535897932385
#define inf 9e18
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
typedef pair<long long, long long> ii;
#define S second
#define F first
ll max(ll a,ll b){if(a>b){return a;}return b;}
ll min(ll a,ll b){if(a<b){return a;}return b;}
#define MAXN 200005
// Comment this out for interactice problem
// #define endl '\n'
// string to integer stoi() Remember: it takes string not character
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
 
// To compile--> g++ -std=c++0x -o output one.cpp
// To run--> ./output
set<ll> Divisors(ll n){
    set<ll> s1;
    for (int i = 1; i*i<=n; ++i)
    {
        if(n%i==0){
            s1.insert(i);
            s1.insert(n/i);
        }
    }
    return s1;
}

int main() 
{ 
    fastio;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll n;
    cin>>n;
    ll a[n+1];
    ll b[n+1];
    for (int i = 1; i < n+1; ++i)
    {
        cin>>a[i];
        b[i]=0;
    }

    for (int i = n; i>=1; i--)
    {
        ll sum=0;
        for (int j = i; j<=n; j+=i)
        {
            sum+=b[j];
        }
        if((sum%2)!=(a[i]%2)){
            b[i]=1;
        }
        else{
            b[i]=0;
        }
    }

    vector<ll> v;
    for (int i = 1; i < n+1; ++i)
    {
        if(b[i]==1){
            v.push_back(i);
        }
    }

    cout<<v.size()<<endl;
    for (int i = 0; i < v.size(); ++i)
    {
        cout<<v[i]<<endl;
    }

    return 0;
}
