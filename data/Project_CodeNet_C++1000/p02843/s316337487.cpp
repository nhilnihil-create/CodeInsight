#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int X;
    cin >> X;
    int C;
    C = X / 100;
    if(C * 100 <= X && X <= C * 105){
        cout << 1 << endl;
        return 0;
    }
    cout << 0 << endl;
}