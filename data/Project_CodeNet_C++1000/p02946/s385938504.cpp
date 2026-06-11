#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, x,hidari, migi;
    cin >> k >> x;
    hidari = x - k + 1;
    migi = x + k - 1 ;
    for (int i = 0; i < migi - hidari+1; i++){
        cout << i + hidari << " ";
    }
    cout << endl;
}