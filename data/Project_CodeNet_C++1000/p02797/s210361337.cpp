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

int main(){
    int N, K;
    ll S;
    cin >> N >> K >> S;

    vector<ll> ans;
    rep(i,N){
        if (i < K){
            ans.push_back(S);
        }
        else{
            if (S < 1e9){
                ans.push_back(S+1);
            }
            else{
                ans.push_back(1);
            }
        }
    }
    
    rep(i,ans.size()){
        printf("%lld%c", ans[i], i==N-1?'\n':' ');
    }
}