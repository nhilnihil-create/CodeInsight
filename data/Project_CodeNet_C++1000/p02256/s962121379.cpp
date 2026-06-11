#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cmath>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)
#define cube(x) (x) * (x) * (x)

const int INF = 1e9;

using namespace std;

int euclid(int a, int b){
    if (a%b == 0)
        return b;
    if (b%a == 0)
        return a;
    return (a>b) ? euclid(a%b, b) : euclid(a, b%a);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << euclid(a, b) << endl;
    return 0;
}