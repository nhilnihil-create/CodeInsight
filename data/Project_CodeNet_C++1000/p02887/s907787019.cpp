#include<bits/stdc++.h>
#define hell                         1000000007
#define M                            1000000007
#define Maxi                      10000000000000000
#define lcm(a,b)                     (a*b)/__gcd(a,b)
#define ll                           long long
 
#define vll                          vector<ll>
#define vi                           vector<long long>
#define pll                          vector< pair<ll,ll> >
#define pb                           push_back
//#define mp                           make_pair
#define all(v)                       v.begin(),v.end()
#define lbnd                         lower_bound
#define ubnd                         upper_bound
#define bs                           binary_search
#define F                            first  
#define S                            second
#define rep(i,a,b)                   for(i=a;i<b;i++)
#define parr(a,n)                    for(i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
#define pcont(a)                     for(auto i:a) cout<<i<<" ";cout<<endl;
#define ret(x)                       return cout<<x,0;
#define dbg(x)                       cout << #x << " is " << x << endl;
#define endl                           '\n'
 //const ll infl=0x3f3f3f3f3f3f3f3fLL;

 #define pi                           3.141592653589793238
// Debug //
 
#define trace(x)                 cerr << #x << ": " << x << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

using namespace std;
//ll a[200005];



int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n;
    string s;
    cin>>n>>s;

    string t="";
    t+=s[0];
    for(ll i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
            continue;
        else
            t+=s[i];
    }

    ll x=t.size();
    cout<<x<<endl;

}