#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long w[n];

    for(long long i = 0; i < n; i++) cin >> w[i];

    long long minv = 1e9;
    for(long long t = 1; t < n; t++){
        long long s1 = 0, s2 = 0;
        for(long long i = 0; i < n; i++){
            if(i <= t) s1 += w[i];
            else s2 += w[i];
        }
        minv = min(minv, abs(s1-s2));
    }

    cout << minv << endl;
    return 0;
}