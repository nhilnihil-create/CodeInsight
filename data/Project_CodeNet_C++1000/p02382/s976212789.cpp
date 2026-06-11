#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    int n;
    cin >> n;
    int x[n], y[n];
    FOR(i, 0, n) cin >> x[i];
    FOR(i, 0, n) cin >> y[i];
    double p1 = 0, p2 = 0, p3 = 0, pmugen = 0;
    FOR(i, 0, n){
        p1 += fabs(x[i]-y[i]);
        p2 += pow(fabs(x[i]-y[i]), 2);
        p3 += pow(fabs(x[i]-y[i]), 3);
        pmugen = max(pmugen, fabs(x[i]-y[i]));
    }
    p2 = pow(p2, 0.5);
    p3 = pow(p3, 0.3333333333);
    printf("%.05lf\n", p1);
    printf("%.05lf\n", p2);
    printf("%.05lf\n", p3);
    printf("%.05lf\n", pmugen);
}