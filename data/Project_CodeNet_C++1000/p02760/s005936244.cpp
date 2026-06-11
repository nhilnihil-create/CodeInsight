#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main() {
    IOS;
    int a[3][3] = {}, n, b[3][3] = {}, c;
    for (int i = 0; i <3; i++){
        for (int j = 0; j <3; j++){
            cin >> a[i][j];
        }
    } 
    cin >> n;
    while (n--) {
        cin >> c;
        for (int i = 0; i <3; i++){
            for (int j = 0; j <3; j++){
                if (c == a[i][j]){
                    b[i][j] = 1;
                }
            }
        }   
    }
    if (b[0][0] && b[0][1] && b[0][2]) cout << "Yes";
    else if (b[1][0] && b[1][1] && b[1][2]) cout << "Yes";
    else if (b[2][0] && b[2][1] && b[2][2]) cout << "Yes";
    else if (b[0][0] && b[1][0] && b[2][0]) cout << "Yes";
    else if (b[0][1] && b[1][1] && b[2][1]) cout << "Yes";
    else if (b[0][2] && b[1][2] && b[2][2]) cout << "Yes";
    else if (b[0][0] && b[1][1] && b[2][2]) cout << "Yes";
    else if (b[2][0] && b[1][1] && b[0][2]) cout << "Yes";
    else cout << "No";
}