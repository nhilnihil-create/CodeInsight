#include <bits/stdc++.h>
using namespace std;

#define fa(x,v) for(auto x:v)
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define spc " "
#define endl '\n'
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define len(s) (ll)int(s.length())
#define sz(v) (ll)int(v.size())
#define MOD 1000000007

void Fast_IO() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef rsd511
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    #endif
    #ifndef rsd511
    #define trace(...) {}
    #define cotra(...) {}
    #endif
} 

// Code Here

int main()
{
    Fast_IO();
    ll n; cin >> n;
    if(n % 1000 == 0) cout << 0;
    else {
    	ll pay = (n / 1000 + 1) * 1000;
    	cout << pay - n;
    }
    return 0;
}