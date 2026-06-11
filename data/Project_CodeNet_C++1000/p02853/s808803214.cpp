#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int code = 0;
    int mac = 0;
    if(x == 3){
        code = 100000;
    } else if(x == 2){
        code = 200000;
    } else if(x == 1){
        code = 300000;
    }
    if(y == 3){
        mac = 100000;
    } else if(y == 2){
        mac = 200000;
    } else if(y == 1){
        mac = 300000;
    }
    if(code + mac == 600000){
        cout << 1000000 << endl;
    } else {
        cout << code + mac << endl;
    }
}