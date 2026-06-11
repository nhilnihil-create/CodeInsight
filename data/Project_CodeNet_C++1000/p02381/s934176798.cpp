#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cmath>
 
#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)
 
const int INF = 1e9;
 
using namespace std;
 
int main() {
    int n;
    int s;
    stringstream result;
    result << setprecision(10);
    while(1) {
        long double total = 0;
        long double sqtotal = 0;
        long double v;
        cin >> n;
        if (!n)
            break;
        REP(i, n) { cin >> s; total += s; sqtotal += square(s); }
        v = sqtotal / n - square(total/n);
        result << sqrt(v) << endl;
    }
    cout << result.str();
 
    return 0;
}