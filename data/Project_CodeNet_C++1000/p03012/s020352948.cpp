#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl;
#define INF 1ll<<60;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n; cin >> n;
    int w[n];
    int all=0;
    rep(i, n){
        cin >> w[i];
        all+=w[i];
    }

    int ans=100100, s1=0, s2=0;
    rep(i, n){
        s1+=w[i];
        s2 = all-s1;
        if(ans>abs(s1-s2)){
            ans = abs(s1-s2);
        }
    }
    out(ans);
}