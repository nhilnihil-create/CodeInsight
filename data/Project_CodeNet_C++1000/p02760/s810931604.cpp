#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int a[3][3];
    rep(i,3) rep(j,3) cin >> a[i][j];
    int n;
    cin >> n;
    rep(i,n){
        int b;
        cin >> b;
        rep(j,3) rep(k,3) if(a[j][k] == b) a[j][k] = 0;
    }
    rep(i,3){
        if(a[i][0] == a[i][1] && a[i][1] == a[i][2]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    rep(j,3){
        if(a[0][j] == a[1][j] && a[1][j] == a[2][j]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    if(a[0][0] == a[1][1] && a[1][1] == a[2][2]){
        cout << "Yes" << endl;
        return 0;
    }
    if(a[0][2] == a[1][1] && a[1][1] == a[2][0]){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}