/**So..a**/
#include<bits/stdc++.h>
//#include <chrono>
// Success after trying 5 hour 11 minute :(


using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define PB(x, v) x.push_back(v);
#define M_P(a, b) make_pair(a, b)
#define pll pair<ll, ll>
#define ll long long
#define mll map<ll, ll>
#define vl vector<ll>
#define fa(x, v) for(auto x: v)
#define fr(i, a, b) for(ll i= a;i <=b; i++)
#define TEST  int test; cin >> test; while(test--)
#define FTEST int TesT; cin >> TesT; for(int test = 1; test<=TesT; test++)

#define B_ begin()
#define E_ end()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define NL_ "\n"
#define F first
#define S second
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second

#define MOD 1000000007
#define  ull unsigned long long

ll POW(ll b, ll p)
{
    ll res = 1;
    while(p)
    {
        if(p%2)
        {
            res*=b;
            res%=MOD;
        }
        b*=b;
        b%=MOD;
        p/=2;
    }
    return res%MOD;
}

int main()
{

    ll n;
    scanf("%lld", &n);
    ll  ans = POW(10, n) - POW(9, n);
    ans += MOD;
    ans  = ans - POW(9, n);
    ans+=MOD;
    ans%=MOD;
    ans+=POW(8, n);

    ans%=MOD;
    printf("%lld" , ans);

    return 0;
}
