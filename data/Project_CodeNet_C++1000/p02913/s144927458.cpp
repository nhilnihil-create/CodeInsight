#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

vector<int> z_algorithm(string s){
    int n = s.size();
    vector<int> ret(n);
    ret[0] = n;
    int i = 1, j = 0;
    while(i < n){
        while(i+j < n && s[j] == s[i+j]) j++;
        ret[i] = j;
        if(j == 0) {i++; continue;}
        int k = 1;
        while(i+k < n && k+ret[k] < j) {ret[i+k] = ret[k], k++;}
        i += k, j -= k; 
    }
    return ret;
}

int main(){
    int N;
    string S, now = "";
    cin >> N >> S;
    int ans = 0;
    rep3(i, N-1, 0){
        now = S[i]+now;
        vector<int> res = z_algorithm(now);
        rep(i, res.size()){
            ans = max(ans, min(i, res[i]));
        }
    }
    cout << ans << endl;
}