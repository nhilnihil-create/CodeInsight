#include<bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;
    if(X < 600) {
        cout <<8;
    } else if(X < 800) {
        cout << 7;
    } else if(X < 1000) {
        cout << 6;
    } else if(X < 1200) {
        cout << 5;
    } else if(X < 1400) {
        cout << 4;
    } else if(X < 1600) {
        cout << 3;
    } else if(X < 1800) {
        cout << 2;
    }else {
        cout << 1;
    }
    return 0;
}