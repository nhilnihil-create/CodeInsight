#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)

void manhattan(vector<int> x, vector<int> y) {
    double s = 0;
    REP(i,x.size()) {
        s += abs(x[i] - y[i]);
    }
    printf("%6f\n", s);
}

void euclid(vector<int> x, vector<int> y) {
    double s = 0;
    REP(i,x.size()) {
        s += (x[i] - y[i]) * (x[i] - y[i]);
    }
    printf("%6f\n", sqrt(s));
}

void minkovski3(vector<int> x, vector<int> y) {
    double s = 0;
    REP(i,x.size()) {
        s += pow(abs(x[i] - y[i]), 3);
    }
    printf("%6f\n", pow(s, 1.0/3));
}

void chevishev(vector<int> x, vector<int> y) {
    double s = 0;
    REP(i,x.size()) {
        s = max(s, (double)abs(x[i] - y[i]));
    }
    printf("%6f\n", s);
}

int main() {
    int n;
    cin >> n;
    vector<int> x, y;
    REP(i,n) {
        int p;
        cin >> p;
        x.push_back(p);
    }
    REP(i,n) {
        int p;
        cin >> p;
        y.push_back(p);
    }
    manhattan(x,y);
    euclid(x,y);
    minkovski3(x,y);
    chevishev(x,y);
    return 0;
}