#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int a[3][3];
int d[3][3];
int main() {
    int count = 0;
    rep(i, 3){
        rep(j, 3){
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    rep(k, n) {
        int x;
        cin >> x;
        rep(i, 3){
            rep(j, 3){
                if(a[i][j] == x){
                    d[i][j] = 1;
                }
            }
        }
    }
    bool ans = false;
    rep(i, 3) {
        int count = 0;
        rep(j, 3){
            count += d[i][j];
        }
        if(count == 3){
            ans = true;
        }
    }
    rep(i, 3) {
        count = 0;
        rep(j,3){
            count += d[j][i];
        }
        if(count == 3){
            ans = true;
        }
        count = 0;
        rep(j ,3) {
            count += d[j][j];
        }
        if(count == 3){
            ans = true;
        }
        count = 0;
        rep(j, 3){
            count += d[j][2 - j];
        }
        if(count == 3){
            ans = true;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
