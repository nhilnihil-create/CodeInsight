#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n;
    string s;
    cin >> n >> s;
    set<string> st1;
    for(int i = 0; i < n; i++){
        set<string> st2 = st1;
        for(auto stt: st2){
            if (stt.size() == 3) continue;
            if (st2.find(stt+s[i]) == st2.end()) st1.insert(stt+s[i]);
        }
        st1.insert({s[i]});
    }
    int ans = 0;
    for(auto stt: st1){
        if (stt.size() == 3) ans++;
    }
    cout << ans << endl;
    return 0;
}