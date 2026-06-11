#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long double> v(n);

    for(long long i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    for(long long i = 0; i < n-1; i++){
        v[i+1] = (v[i]+v[i+1])/2.0;
    }

    printf("%.10Lf\n", v[n-1]);
    return 0;
}