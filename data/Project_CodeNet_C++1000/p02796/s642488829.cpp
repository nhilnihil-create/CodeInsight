#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

bool comp(pair<ll,ll> a, pair<ll,ll> b){
    return a.first+a.second < b.first+b.second;
}

int main(){
    int N; cin >> N;
    vector<ll> X(N), L(N);
    vector<pair<ll,ll>> XL(N);
    rep(i,N) cin >> XL[i].first >> XL[i].second;

    sort(XL.begin(), XL.end(), comp);

    int ans = 0;
    ll right_end = -INF;
    rep(i,N){
        if (right_end <= XL[i].first-XL[i].second){
            right_end = XL[i].first+XL[i].second;
            ans++;
        }
    }

    cout << ans << endl;

}