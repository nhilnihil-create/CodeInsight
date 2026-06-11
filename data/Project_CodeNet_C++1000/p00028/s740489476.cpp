#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(void)
{
    int n, a[100], mode = 0;
    rep(i, 100) {
        a[i] = 0;
    }
    while (cin >> n)
        a[n]++;
    
    rep(i,100) {
        if (mode < a[n]) {
            mode = a[n];
        }
    }
    
    rep(i,100) {
        if (a[i] == mode) {
            cout << i << endl;
        }
    }
    
    return 0;
}