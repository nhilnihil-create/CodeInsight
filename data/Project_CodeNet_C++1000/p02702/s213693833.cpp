#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;

int main(){
    string S; cin >> S;
    int n = S.size();

    vector<int> mod_counter(2019, 0);
    mod_counter[0] = 1;
    int mul = 1;
    int now = 0;
    for (int i = n - 1; i >= 0; i--){
        now = ((mul * (S[i] - '0') % 2019) + now) % 2019;
        mod_counter[now]++;
        mul =  (mul * 10) % 2019;
    }

    ll ans = 0;
    rep(i, mod_counter.size()){
        ll count = mod_counter[i];
        ans += count * (count-1) / 2;
    }

    cout << ans << endl;

}