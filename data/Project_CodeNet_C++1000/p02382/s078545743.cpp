#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,e)for(int i=0;i<e;i++)
using namespace std;

int main(){
    int n, i, j;
    int x[1005];
    int y[1005];
    double D=0;
    cin >> n;
    rep(i,n) cin >> x[i];
    rep(i,n) cin >> y[i];
    rep(i,n) D += abs(x[i]-y[i]);
    printf("%.8f\n", D);
    D = 0;
    rep(i,n) D += pow(x[i]-y[i], 2);
    printf("%.8f\n", sqrt(D));
    D = 0;
    rep(i,n) D += pow(abs(x[i]-y[i]), 3);
    printf("%.8f\n", pow(D,(double)1/3));
    D = 0;
    int max = abs(x[0]-y[0]);
    rep(i, n) if(max < abs(x[i]-y[i])) max = abs(x[i]-y[i]);
    D = max;
    printf("%.8f\n", D);
    return 0;
}
