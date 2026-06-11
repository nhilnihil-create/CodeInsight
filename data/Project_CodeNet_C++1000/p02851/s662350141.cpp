#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<ll> s(N+1);
    for(int i = 0; i < N; i++) s[i+1] = s[i] + a[i];
    for(int i = 1; i <= N; i++) s[i] = (s[i] - i) % K;

    ll res = 0;
    map<ll, ll> mp;
    for (int i = 0; i <= N; i++) {
        if (i >= K) mp[s[i-K]]--;
        res += mp[s[i]]++;
    }
    cout << res << '\n';
}
