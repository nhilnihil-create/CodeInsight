#include <bits/stdc++.h>
using namespace std;

int main() {
    int K, X;
    cin >> K >> X;
    int l = X - K + 1;
    int r = X + K;
    for(int i = l; i < r; i++) {
        if(i == l)
            cout << i;
        else
            cout << " " << i;
    }
    cout << endl;
}