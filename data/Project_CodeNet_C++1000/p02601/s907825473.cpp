#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a, b, c;
    int k;
    vector<int> binary = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    cin >> a >> b >> c;
    cin >> k;
    bool flg = false;
    for (int i=0;i<=k;i++){
        for (int j=0;j<=k;j++){
            if (a < b*binary[i] && b*binary[i] < c*binary[j] && i+j==k){
                flg = true;
            }
        }
    }
    if (flg){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
