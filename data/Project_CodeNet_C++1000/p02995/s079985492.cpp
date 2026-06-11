#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

LL gcd(LL val1, LL val2);

int main(){
    LL A, B, C, D;
    cin >> A >> B >> C >> D;

    LL min_gcd = 0;
    if(C < D){
        min_gcd = gcd(C, D);
    }else{
        min_gcd = gcd(D, C);
    }
    LL common = min_gcd * (C/min_gcd) * (D/min_gcd);

    LL count_1 = B - (B/C) - (B/D) + (B/(common));
    LL count_2 = (A-1) - ((A-1)/C) - ((A-1)/D) + ((A-1)/(common));

    LL ans = count_1 - count_2;
    cout << ans << endl;
    return 0;


}

LL gcd(LL min_val, LL max_val){
    LL r = max_val % min_val;
    if(r == 0){
        return min_val;
    }
    return gcd(r, min_val);
}