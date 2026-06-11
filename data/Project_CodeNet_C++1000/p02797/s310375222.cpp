#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<62;
const int IINF = 1000000000;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

int main(){
    int N, K, S; cin >> N >> K >> S;
    vector<int> ans(N);

    rep(i,N){
        if (S < 1e9){
            if(K > 0){
                ans[i] = S;
            }
            else{
                ans[i] = 1e9;
            }
        }
        else{
            if(K > 0){
                ans[i] = S;
            }
            else{
                ans[i] = 1;
            }
        }
        K--;
    }
    rep(i,N){
        printf("%d%c", ans[i], i==N-1?'\n':' ');
    }
}
