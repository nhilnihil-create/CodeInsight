#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> um;
    rep(i,n){
        string s; cin >> s;
        sort(s.begin(), s.end());
        um[s]++;
    }
    ll ans = 0;
    for(pair<string, int> p: um){
        int cnt = p.second;
        if(cnt >= 2){
            ans += ((ll)cnt * (cnt - 1)) / 2;
        }
    }
    cout << ans << endl;
    
    return 0;
}