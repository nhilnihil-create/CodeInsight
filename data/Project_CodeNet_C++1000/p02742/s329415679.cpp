#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int h, v;
    cin >> h >> v;
    if(h == 1 || v == 1) {
        cout << 1 << endl;
        return 0;
    }
    h *= v;
    if(h%2)
        cout << (h/2)+1 << endl;
    else
        cout << h/2 << endl;
    return 0;
}
