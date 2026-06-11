#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)

double ave(vector<int> v) {
    int sum = 0;
    REP(i,v.size()) {
        sum += v[i];
    }
    return (double) sum / v.size();
}

void solve10c(int a) {
    vector<int> v;
    vector<int> vv;
    REP(i,a) {
        int j;
        cin >> j;
        v.push_back(j);
        vv.push_back(j*j);
    }
    double stdev = sqrt(ave(vv) - ave(v) * ave(v));
    printf("%6f\n", stdev);
}

int main() {
    int a;
    while(cin >> a, a) {
        solve10c(a);
    }
    return 0;
}