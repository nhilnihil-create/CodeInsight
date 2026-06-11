#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n);
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= 2;
        sum += a[i];
    }
    sum /= 2;

    vector<long long> v(n);

    long long cnt = n/2;
    for(long long i = 0; i < cnt; i++){
        sum -= a[2*i];
    }
    v[n-1] = sum;
    v[0] = a[n-1] - v[n-1];

    for(long long i = n-2; i >= 0; i--){
        v[i] = a[i] - v[i+1];
    }

    for(long long i = 0; i < n; i++){
        if(i == n-1) printf("%lld\n", v[i]);
        else printf("%lld ", v[i]);
    }

    return 0;
}