#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>
#include<map>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    ll a[n];
    rep(i, n) cin >> a[i];
    vector<P> cnt(60);
    rep(i, n){
        rep(j, 60){
            if ((a[i] >> j) & (ll)1) cnt[j].first++;
            else cnt[j].second++; 
        }
    }
    ll ans = 0;
    ll bit = 1;
    rep(i, 60){
        ll num;
        num = (ll)cnt[i].first * (ll)cnt[i].second;
        num %= mod;
        ans += num * bit;
        ans %= mod;
        bit *= 2;
        bit %= mod;
    }
    cout << ans << endl;
}