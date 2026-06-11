#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

#define PI 3.141592653589793
#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define RFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)

int main() {
    int n;
    double s[1001];
    while(cin >> n) {
        if (n==0) break;
        double a,m,sum;
        sum = a = 0.0;
        REP(i,n) {
            cin >> s[i];
            sum += s[i];
        }
        m = sum/(double)n;
        REP(i,n) {
            a += pow(s[i]-m, 2);
            //cout << s[i] << m << a << endl;
        }
        //cout << a << endl;
        a=sqrt(a/(double)n);
        printf("%.5f\n", a);
    }
    return 0;
}

