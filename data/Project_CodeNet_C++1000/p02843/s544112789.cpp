#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int X;
    cin >> X;
    bool check = 1;

    int temp = X%100;
    temp = (temp + 4)/5;
    if(X/100 >= temp) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }


    return 0;
}