#include <bits/stdc++.h>
using namespace std;

int main(){

    int x;
    cin >> x;

    int div, mod;
    div = x/100;
    mod = x%100;

    if (mod <= div*5) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}