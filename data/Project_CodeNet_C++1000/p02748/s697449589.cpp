#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int A,B,M;
    cin >> A >> B >> M;
    int a[A],b[B];
    int x[M][3];
    rep(i,A){
        cin >> a[i];
    }
    rep(i,B){
        cin >> b[i];
    }
    rep(i,M){
        rep(j,3){
            cin >> x[i][j];
        }
    }

    int ans=1000000;
    rep(i,M){
        int sum=a[x[i][0]-1]+b[x[i][1]-1]-x[i][2];
        ans=min(ans,sum);
    }
    int a0=1000000;
    int b0=1000000;
    rep(i,A){
        a0=min(a0,a[i]);
    }
    rep(i,B){
        b0=min(b0,b[i]);
    }
        ans=min(ans,a0+b0);
    cout << ans << endl;
}
