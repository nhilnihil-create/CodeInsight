#include <iostream>
#include <string>
#include <algorithm>
#define int long long
using namespace std;

signed main() {
    int n,k,d;
    cin >> n >> k;/*
    while(n > abs(n-k)){
        n = abs(n-k);
        cout << n << endl;
    }*/
    d = n/k;
    n -= d*k;
    while(n > abs(n-k)){
        n = abs(n-k);
    }
    cout << n;

    return 0;
}