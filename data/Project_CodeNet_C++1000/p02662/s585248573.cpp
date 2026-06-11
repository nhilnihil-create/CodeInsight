#include <bits/stdc++.h>
using namespace std;
long long int MOD = 998244353;

int main(){
    int n, s;
    cin >> n >> s;

    vector<long long int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<long long int> exponent(s+1);// formal power series
    exponent[0] = 1;
    for(int i=0; i<n; i++){// * (1 + (1 + x^a[i]))
        vector<long long int> next(s+1);
        for(int j=0; j<=s; j++){
            next[j] += 2 *exponent[j];
            if(j - a[i] >= 0) next[j] += exponent[j-a[i]];
            next[j] %= MOD;
        }
        exponent = next;
    }
    cout << exponent[s] << endl;
    return 0;
}