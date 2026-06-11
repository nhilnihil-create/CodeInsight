#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a[3][3];
    for(int i=0;i<3;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int b;
        cin >> b;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(a[j][k] == b) a[j][k] = 0;
            }
        }
    }
    if(a[0][0] == 0 && a[0][1] == 0 &&a[0][2]==0) cout << "Yes" << endl;
    else if(a[1][0] ==0 && a[1][1] == 0 &&a[1][2] ==0) cout << "Yes" << endl;
    else if(a[2][0] == 0 && a[2][1] == 0 && a[2][2] == 0) cout << "Yes" << endl;
    else if(a[0][0] == 0 &&a[1][0] == 0 &&a[2][0]==0) cout << "Yes" << endl;
    else if(a[0][1] == 0 &&a[1][1] == 0&&a[2][1]==0) cout << "Yes" << endl;
    else if(a[0][2] == 0&&a[1][2] == 0 &&a[2][2]==0) cout << "Yes" << endl;
    else if(a[0][0] == 0 &&a[1][1] == 0 &&a[2][2]==0) cout << "Yes" << endl;
    else if(a[0][2] ==0 && a[1][1] == 0 &&a[2][0]==0) cout << "Yes" << endl;
    else cout << "No" << endl;
}