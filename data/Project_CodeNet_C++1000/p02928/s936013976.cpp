#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}
    ll a_ = 0;
    ll b_ = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[i] > a[j]) a_++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (a[i] < a[j]) b_++;
        }
    }

    //cout << a_ << " " << b_ << endl;

    ll pat = k*(k-1)/2;
    pat %= MOD;
    ll ans = (a_*k) + b_*pat;
    cout << ans%MOD << endl;

}

