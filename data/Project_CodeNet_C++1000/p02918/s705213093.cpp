#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    VI cnts;
    char c = s[0];
    for(int i = 1; i < n; i++){
        if (s[i] != c){
            cnts.push_back(1);
            c = s[i];
        }
    }
    cnts.push_back(1);
    
    int ans = 0;
    rep(i,n-1){
        if (s[i] == s[i+1]) ans++;
    }

    int sz = cnts.size();
    if (sz / 2 <= k){
        ans += 2 * (sz / 2);
        if (sz % 2 == 0) ans--;
    }else{
        ans += 2 * k;
    }
    cout << ans << endl;
    return 0;
}