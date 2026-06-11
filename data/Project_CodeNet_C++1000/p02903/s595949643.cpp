#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int H, W;
int A, B;

signed main(){
    cin >> H >> W >> A >> B;
    rep(i, B){
        string ans = "";
        rep(j, A) ans += "0";
        rep(j, W-A) ans += "1";
        cout << ans << endl;
    }
    rep(i, H-B){
        string ans = "";
        rep(j, A) ans += "1";
        rep(j, W-A) ans += "0";
        cout << ans << endl;
    }
}