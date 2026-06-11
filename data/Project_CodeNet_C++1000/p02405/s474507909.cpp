#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)


void solve5c(int a, int b) {
    REP(i,a) {
        REP(j,b) {
            if (i%2==0) {
                if (j%2==0) {
                    cout << "#";
                }else {
                    cout << ".";
                }
            }else {
                if (j%2==0) {
                    cout << ".";
                }else {
                    cout << "#";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int a, b;
    while(cin >> a >> b, a+b) {
        solve5c(a, b);
    }
    return 0;
}