#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    set<int> st;
    map<int, int> wa;
    int ans = 0;
    rep(i,m){
        int p;
        string s;
        cin >> p >> s;
        if(s == "AC"){
            st.insert(p);
        }
        else{
            if(st.find(p) == st.end()) ++wa[p];
        }
    }
    cout << st.size() << " ";
    for(auto p : st){
        ans += wa[p];
    }
    cout << ans << endl;
    return 0;
}
