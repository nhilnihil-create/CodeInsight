#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cmath>
#include <vector>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)

const int INF = 1e9;

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    REP(i, n){
        cin >> a[n-1-i];
    }
    REP(i, n-1) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    return 0;
}