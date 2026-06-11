#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n, m; cin >> n >> m;
    vector<pii> A(n);
    rep(i, n){
        int a, b; cin >> a >> b;
        a = m - a; //a日目までに請けないといけない
        A[i] = {a, b};
    }
    sort(all(A), greater<pii>());
    ll res = 0; int index = 0;
    priority_queue<int> que;
    for(int i=m; i>=0; i--){
        while(index < n){
            if(A[index].first != i)break;
            que.push(A[index].second);
            index++;
        }
        if(que.size()){
            int point = que.top(); que.pop();
            res += point;
        }
    }
    cout << res << ln;
}
    
