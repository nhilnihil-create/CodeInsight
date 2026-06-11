#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)


void solve5b(int a, int b) {
    REP(i,b) {
        cout << "#";
    }
    cout << endl;
    REP(i,a-2) {
        cout << "#";
        REP(j,b-2) {
            cout << ".";
        }
        cout << "#";
        cout << endl;
    }
    REP(i,b) {
        cout << "#";
    }
    cout << endl;
    cout << endl;
}

int main() {
    int a, b;
    while(cin >> a >> b, a+b) {
        solve5b(a, b);
    }
    return 0;
}