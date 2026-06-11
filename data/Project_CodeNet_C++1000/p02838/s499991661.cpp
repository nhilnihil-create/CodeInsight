#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long mod = 1e9+7;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n);

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    long long res = 0;
    long long two_factor = 1;

    for(long long d = 0; d < 60; d++){
        long long even = 0, odd = 0;
        for(long long i = 0; i < n; i++){
            if(a[i] & ((long long)1 << d)) odd++;
            else even++;
        }
        long long add = ((odd*even) % mod) *(two_factor % mod);
        res = (res + add) % mod;
        two_factor = (two_factor* 2) % mod;
    }
    cout << res << endl;
    return 0;
}