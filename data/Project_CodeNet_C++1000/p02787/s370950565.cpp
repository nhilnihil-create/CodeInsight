#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
const ll mod = (ll)1e9 + 7;
signed main(){
    speed;
    int h, n; cin >> h >> n;
    vector<pair<int, int>> v(n);
    vector<int> dp(h + 1, INT_MAX);
    rep(i, 0, n) {
        cin >> v[i].first;
        cin >> v[i].second;
    }
    dp[0] = 0;
    for(int i = 0; i < h; i++) {
        if(dp[i] != INT_MAX) {
            for(int j = 0; j < n; j++) {
                int k = i + v[j].first;
                if(k > h) k = h;
                if(dp[k] > dp[i] + v[j].second) {
                    dp[k] = dp[i] + v[j].second;
                }
            }
        }
    }
    cout << dp[h] << endl;
    return 0;
}