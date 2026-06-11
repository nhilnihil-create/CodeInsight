#include <bits/stdc++.h>


using namespace std;
using ll = long long;


int main() {
    int n;
    cin >> n;
    int r = n % 1000;
    if(r == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1000- r << "\n";
    }



    return 0;
}

