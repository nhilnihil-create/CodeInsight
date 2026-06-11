#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    ll n;
    cin >> n;
    ll a[n+1], b[n];
    rep(i, n+1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, n){
        ans += min(a[i], b[i]);
        b[i] = max((ll)0, b[i] - a[i]);
        ans += min(a[i+1], b[i]);
        a[i+1] = max((ll)0, a[i+1] - b[i]);
    }
    cout << ans << endl;
}