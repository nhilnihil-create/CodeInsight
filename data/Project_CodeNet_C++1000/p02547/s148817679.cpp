//https://atcoder.jp/contests/abc178/tasks/abc178_f
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN=1e2+4;
int sz[MAXN][2+2];
 
int main() {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        cin>>sz[i][1]>>sz[i][2];
    }

    for (int i=1; i<=n-2; i++) {
        if (sz[i][1]==sz[i][2] && sz[i+1][1]==sz[i+1][2] && sz[i+2][1]==sz[i+2][2]) {
            cout<<"Yes\n";
            return 0;
            }         
    }
    cout<<"No\n";
 
    return 0;
}