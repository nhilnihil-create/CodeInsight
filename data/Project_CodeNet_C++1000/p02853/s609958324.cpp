#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
    int x , y;
    cin >> x >> y;
    if(x == 1 && y == 1){
        cout << 1000000 << endl;
    }
    else{
        int yen = 0;
        if(x == 1){
            yen += 300000;
        }
        if(x == 2){
            yen += 200000;
        }
        if(x == 3){
            yen += 100000;
        }
        if(y == 1){
            yen += 300000;
        }
        if(y == 2){
            yen += 200000;
        }
        if(y == 3){
            yen += 100000;
        }
        cout << yen << endl;
    }
}
