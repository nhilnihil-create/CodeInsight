#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void dfs(int n, char mc, string str) {
    if(str.size() == n) {
        cout << str << endl;
        return;
    }
    for(char c = 'a'; c <= mc+1; c++) {
        dfs(n, max(c,mc), str+c);
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;    
    string a = "a";
    dfs(n, 'a', a);
}
