#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

char al[11] = {'a','b','c','d','e','f','g','h','i','j','k'};

int n;

void dfs(string s){
    if(s.size() == n){
        cout << s << endl;
        return;
    }
    set<char> st;
    int idx = 0;
    rep(i,s.size()){
        st.insert(s[i]);
        chmax(idx, s[i]-'a');
    }
    for(auto e : st){
        dfs(s + e);
    }
    ++idx;
    char nex = 'a' + idx;
    dfs(s + nex);
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    dfs("a");
    return 0;
}
