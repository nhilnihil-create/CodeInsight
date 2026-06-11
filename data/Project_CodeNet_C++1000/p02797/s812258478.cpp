#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k, s;
    cin >> n >> k >> s;
    rep(i,k) cout << s << " ";
    if(s == INF){
        rep(i,n-k) cout << INF - 1 << " ";
    }
    else{
        rep(i,n-k) cout << s+1 << " ";
    }
    cout << endl;
    return 0;
}