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
const int MAX_N = 200010;

int a[MAX_N];
int f[MAX_N];
ll n, k;

bool C(ll x){
    ll sm = 0;
    rep(i, n){
        sm += max((ll)0, a[i] - x / f[i]);
    }
    // cout << sm << endl;
    return sm <= k;
}

int main(){
    
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(a, a + n);
    sort(f, f + n, greater<int>());
    ll l = -1, r = 1001001001001001001;
    while(l + 1 < r){
        ll mid = (l + r) / 2;
        if(C(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}