#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long x[n];
    for(long long i = 0; i < n; i++) cin >> x[i];

    long long minv = 1e9;

    for(long long i = -1000; i <= 1000; i++){
        long long sum = 0;
        for(long long j = 0; j < n; j++){
            sum += (x[j]-i)*(x[j]-i);
        }
        minv = min(minv, sum);
    }
    cout << minv << endl;
    return 0;
}