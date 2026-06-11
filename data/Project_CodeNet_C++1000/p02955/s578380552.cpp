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

int main(){
    int N, K;
    cin >> N >> K;
    int A[N], sum = 0;
    rep(i, N){
        cin >> A[i];
        sum += A[i];
    }
    vector<int> ds;
    for(int i = 1; i*i <= sum; i++){
        if(sum%i == 0){
            ds.pb(i), ds.pb(sum/i);
        }
    }
    sort(all(ds), greater<int>());
    for(int e: ds){
        vector<int> memo;
        int s = 0;
        rep(i, N){
            memo.pb(A[i]%e);
            s += A[i]%e;
        }
        sort(all(memo), greater<int>());
        int cnt = 0;
        rep(i, s/e) cnt += e-memo[i];
        if(cnt <= K){
            cout << e << endl;
            break;
        }
    }
}