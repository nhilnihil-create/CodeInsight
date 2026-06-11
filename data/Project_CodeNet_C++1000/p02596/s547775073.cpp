#include <bits/stdc++.h>
using namespace std;



















/* 

Kが7の倍数なら1，11，…からK/7の倍数を探す
そうでなければ1，11，…からKの倍数を探す

*/

// ax = 1 (mod m) の解
int64_t modinv(int64_t a, int64_t m) {
    int64_t b = m, u = 1, v = 0;
    while (b) {
        int64_t t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}


// 1, 11, …に初めてAの倍数が出てくる項数
int64_t first (int64_t A) {
    int result = -1;
    
    if (A % 2 == 0 || A % 5 == 0) {
        return -1;
    }

    if (A == 1) {
        return 1;
    }
    
    // A % 10^n の周期を求める
    vector<int> period(1, 1);
    int n = 10 % A;
    while (n != 1) {
        period.push_back(n % A);
        n *= 10;
        n %= A;
    }

    /* for (int i = 0; i < period.size(); i++) {
        cout << period[i] << " ";
    }
    cout << endl; */

    // 周期をTとして，1がT個並んだものをAで割った余りをunit_residueとする
    int64_t T = period.size();
    vector<int64_t> period_sum(T, 1);
    int64_t unit_residue = 0;
    for (int64_t i = 1; i < T; i++) {
         period_sum[i] = (period_sum[i - 1] + period[i]) % A; 
    }
    unit_residue = period_sum[T - 1];

    /* for (int i = 0; i < period_sum.size(); i++) {
        cout << period_sum[i] << " ";
    }
    cout << endl; */
    
    if (unit_residue == 0) {
        int min = 0;
        for (int i = 0; i < T; i++) {
            if (period_sum[i] == 0) {
                return i + 1;
            }
        }
    }

    // 各period_sum[i]に対してunit_residue * x + period_sum[i] = 0 (mod A)の最小解を求める
    int64_t gcd = __gcd(unit_residue, A);
    int64_t inverse = modinv(unit_residue / gcd, A / gcd);
    vector<int64_t> minimum(T, A + 1);
    for(int i = 0; i < T; i++) {
        if (period_sum[i] % gcd == 0) {
            minimum[i] = (inverse * (A / gcd - period_sum[i] / gcd)) % (A / gcd);
        }
    }

    /* for (int i = 0; i < T; i++) {
        cout << minimum[i] << " ";
    }
    cout << endl; */
 
    // minimum[i]が最小となる添え字のうち最小の値をfitとする
    int64_t fit = 0;
    int64_t min = 1000000000;
    for (int i = 0; i < T; i++) {
        if (min > minimum[i]) {
            min = minimum[i];
            fit = i;
        }
    }
    result = T * min + fit + 1;
    return result;
}



int main () {
    int64_t K;
    cin >> K;

    if (K % 7 == 0) {
        cout << first (K / 7) << endl;
    }

    else {
        cout << first (K) << endl;
    }
}