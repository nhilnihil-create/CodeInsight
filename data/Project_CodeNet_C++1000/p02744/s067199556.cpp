#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;

 
int N;
 
void dfs(string s) {
    if (s.length() == N) {
        cout << s << endl;
        return;
    }
    char up = 'a';
    for (char c : s) {
        up = max(up, c);
    }
    for (char c = 'a'; c <= up + 1; c++) {
        dfs(s + c);
    }
    
} 
 
int main() {
    cin >> N;
    string s = "a";
    dfs(s);
}