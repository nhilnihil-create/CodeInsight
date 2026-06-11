#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> b(n);
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i]; 
    }

    sort(a.begin(), a.end(), greater<long long>());

    long long maxv = a[0];
    long long maxv2 = a[1];

    for(long long i = 0; i < n; i++){
        if(b[i] != maxv){
            printf("%lld\n", maxv);
        }
        else{
            printf("%lld\n", maxv2);
        }
    }
    return 0;
}