#include <bits/stdc++.h>
using namespace std;

int main() {
    int X; cin >> X;
    int p=X/100;
    X=X%100;
    p=p-X/5; X=X%5;
    p=p-X/4; X=X%4;
    p=p-X/3; X=X%3;
    p=p-X/2; X=X%2;
    if(X==1) p=p-1;
    if(p<0) cout << 0 << endl;
    else cout << 1 << endl;
}

