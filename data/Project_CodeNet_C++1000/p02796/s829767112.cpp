#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, l, r) for (ll i = (ll)l; i < (ll)(r); i++)
#define INF 1000000000000000000
#define MAX 200001
#define MOD 1000000007

template <typename T > inline string toString(const T &a) {ostringstream oss; oss << a; return oss.str();};

int main(){
    ll now = -2e9;
    ll ans = 0;
    int N;
    cin >> N;
    vector<pair<ll, ll>> v(N);
    rep(i, N){
        ll x, l;
        cin >> x >> l;
        v[i] = {x + l, x - l};
    }
    sort(v.begin(), v.end());
    rep(i, N){
        if(v[i].second < now) continue;
        else{
            now = v[i].first;
            ans++;
        }
    }
    cout << ans << endl;
}