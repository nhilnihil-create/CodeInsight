#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

char c[11] = {'a','b','c','d','e','f','g','h','i','j','k'};

int n;

void dfs(string s){
    if(s.size() == n){
        cout << s << endl;
        return;
    }
    set<char> se;
    int nex = 0;
    rep(j,s.size()){
        if(se.find(s[j]) != se.end()) continue;
        nex++;
        se.insert(s[j]);
        dfs(s+s[j]);
    }
    dfs(s + c[nex]);
    return;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    dfs("a");
    return 0;
}
