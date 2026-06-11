#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef vector<lint> vlint;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

map<lint, lint> trial_division(lint n){
    map<lint, lint> factor;
    lint tmp = (lint)(sqrt(n)) + 1;
    for (lint i = 2; i < tmp; ++i){
        while (n % i == 0){
            n /= i;
            factor[i] ++;
        }
    }
    if (n != 1) factor[n] ++;
    return factor;
};

int main(){
    lint n; cin >> n;
    lint ans = 0;
    // n-1
    for (lint i = 2; i*i <= n-1; i++){
        if ((n-1) % i == 0){
            ans += 2;
            if (i*i == n-1) ans--;
        }
    }
    
    if (n != 2) ans ++;

    //n
    lint k, j;
    for (lint i = 2; i*i <= n; i++){
        if (n % i == 0){
            k = n;
            while (k % i == 0) k /= i;
            if (k % i == 1) ans ++;

            k = n;
            j = n/i;
            if (i == j) continue;
            while (k % j == 0) k /= j;
            if (k % j == 1) ans ++;
        }
    }
    ans ++;
    cout << ans << endl;
}