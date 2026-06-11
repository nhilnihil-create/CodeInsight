#include <bits/stdc++.h>

using namespace std;

int main(){
    int l,r;
    cin >> l >> r;

    int d;
    cin >> d;

    cout << r / d - (l - 1) / d << endl;

    return 0;
}