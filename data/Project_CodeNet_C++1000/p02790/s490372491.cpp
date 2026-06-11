#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(), v.end()
#define sz size()
#define mp make_pair
#define pb push_back
#define rep(p, a, b) for (ll p = a; p < b; p++)
#define F first
#define S second
using namespace std;

typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<ld> vld;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;

int main()
{
    ll t, i, j, k, ans, n, m, sum = 0, x;

    //cin>>t;
    t = 1;
    while (t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1<s2)rep(p,0,(s2[0]-'0'))cout<<s1;
        else rep(p,0,(s1[0]-'0'))cout<<s2;
    }

    return 0;
}
