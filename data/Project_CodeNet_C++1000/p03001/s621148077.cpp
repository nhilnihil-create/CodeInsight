#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    LL W, H, x, y;
    cin >> W >> H >> x >> y;

    double S = 0.5*W*H;
    int count = 0;
    if(2*x==W && 2*y==H){
        count = 1;
    }

    cout << fixed << setprecision(10) << S << " ";
    cout << count << endl;
    return 0;
}