#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> a(3, vector<int> (3, 0));
    for(int i = 0; i<3; i++) {
        for(int j = 0; j<3; j++) {
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i<n; i++) cin >> b[i];
    bool ans = false;

    for(int i = 0; i < 3; i++) {
        for ( int j = 0; j< 3; j++) {
            for(int k = 0; k<n; k++){
                if( a[i][j] == b[k] ) a[i][j] = -1;
            }
        }
    }

    if (a[0][0] == -1 && a[0][1] == -1 && a[0][2] == -1) ans = true;
    else if (a[1][0] == -1 && a[1][1] == -1 && a[1][2] == -1) ans = true;
    else if (a[2][0] == -1 && a[2][1] == -1 && a[2][2] == -1) ans = true;
    else if (a[0][0] == -1 && a[1][0] == -1 && a[2][0] == -1) ans = true;
    else if (a[0][1] == -1 && a[1][1] == -1 && a[2][1] == -1) ans = true;
    else if (a[0][2] == -1 && a[1][2] == -1 && a[2][2] == -1) ans = true;
    else if (a[0][0] == -1 && a[1][1] == -1 && a[2][2] == -1) ans = true;
    else if (a[0][2] == -1 && a[1][1] == -1 && a[2][0] == -1) ans = true;

    if(ans) puts("Yes");
    else puts("No");
}