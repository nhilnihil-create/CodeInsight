#include<bits/stdc++.h>
#define EM 1000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
LL mod = 1e9+7;
using vint = vector<int>;
using vLL = vector<LL>;
using vvint = vector<vector<int>>;
using vvLL = vector<vector<LL>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<vector<bool>> map1(N, vector<bool>(N, false));
    for(int i = 0;i < N;i++) {
        for(int j = 0;j < N;j++) {
            if (s[i] == s[j]) {
                map1[i][j] = true;
            }
        }
    }
    int ans = 0;
    for(int i = 1;i < N ;i++) {
        for(int j = 0;i+j < N;j++) {
            int cj = j;
            if(map1[j][i+j]) {
                for(;i+j < N && map1[j][i+j] && j-cj < i;j++) {}
                ans = max(ans, j-cj);
            }
        }
    }
    for(int i = 1;i < N;i++) {
        for(int j = 0;i+j < N;j++) {
            int cj = j;
            if(map1[i+j][j]) {
                for(;i+j < N && map1[i+j][j] && j-cj < i;j++) {}
                ans = max(ans, j-cj);
            }
        }
    }
    cout << ans << endl;
}

