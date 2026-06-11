#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main() {
    int n, k;
    cin >> n >> k;

    vector<long> nSum(n+1, 0); 
    for (int i = 1; i <= n; i++){
        nSum.at(i) = nSum.at(i-1) + i;
    }
    
    long sumMax, sumMin, cnt = 0;
    for (int i = k; i <= n+1; i++){
        sumMin = nSum.at(i-1);
        sumMax = ( (n-i < 0) ? nSum.at(n) : nSum.at(n) - nSum.at(n-i) );
        cnt = (cnt + sumMax - sumMin + 1) % MOD;
    }

    cout << (int)cnt << endl;

    return 0;
}
