#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<string> vsi;
typedef map<ll, ll> mape;
#define rep(i, a, b) for(ll i=(ll)a;i<=(ll)b;i++)
#define per(i, a, b) for(ll i=(ll)a;i>=(ll)b;i--)
#define fastio {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
//#define N 2100
#define MAX 1234567890
#define f first
#define s second
#define pb push_back
#define mkp make_pair
#define MOD 1000000007

int main()
{
    fastio;

    ll n;
    string s;
    cin >> n >> s;
    ll len = s.size(), integer;
    ll dec = (s[len-2] - '0') * 10 + (s[len-1] - '0');
    if(len == 4) integer = (s[0] - '0') ;
    else integer = 10;
    ll temp = (n * dec) / 100;
    n *= integer;
    cout << n + temp << endl;

    return 0;
}
