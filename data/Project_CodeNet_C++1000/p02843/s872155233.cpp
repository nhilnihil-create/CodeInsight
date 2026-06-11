#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;

    int k = x / 100;

    if(x <= 105 * k) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}