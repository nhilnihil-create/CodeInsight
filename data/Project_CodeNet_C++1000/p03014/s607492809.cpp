#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int h,w;
    cin >> h >> w;
    vector<string>field(h);
    rep(i,h) {
        cin >> field[i];
    }
    vector<vector<int>>L(h,vector<int>(w));
    vector<vector<int>>R(h,vector<int>(w));
    vector<vector<int>>D(h,vector<int>(w));
    vector<vector<int>>U(h,vector<int>(w));
    rep(i,h) {
        int cur = 1;
        rep(j,w) {
            if(field[i][j]=='#') cur = 0;
            L[i][j] = cur;
            cur++;
        }
        // cout << endl;
    }
    rep(i,h) {
        int cur = 1;
        for(int j = w-1;j>=0;j--) {
            if(field[i][j]=='#') cur = 0;
            R[i][j] = cur;
            // cout << R[i][j] << " ";
            cur++;
        }
        // cout << endl;
    }
    rep(j,w) {
        int cur = 1;
        rep(i,h) {
            if(field[i][j]=='#') cur = 0;
            U[i][j] = cur;
            cur++;
        }
    }
    
    rep(j,w) {
        int cur = 1;
        for(int i = h-1;i>=0;i--) {
            if(field[i][j]=='#') cur = 0;
            D[i][j] = cur;
            cur++;
        }
    }
    int ans = 0;
    rep(i,h) rep(j,w) {
        if(field[i][j] == '#') continue;
        int res = L[i][j]+R[i][j]+U[i][j]+D[i][j]-3;
        ans = max(ans,res);
    }
    cout << ans << endl;
}