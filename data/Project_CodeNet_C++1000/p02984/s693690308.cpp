#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<long long> x(n);

    long long sum = 0;

    for(long long i = 0; i < n; i++){
        if(i % 2 == 0){
            sum += 2*a[i];
        }
        else{
            sum -= 2*a[i];
        }
    }

    x[0] = sum/2;

    for(long long i = 1; i < n; i++){
        x[i] = 2*a[i-1] - x[i-1];
    }

    for(long long i = 0; i < n; i++){
        printf("%lld ", x[i]);
    }
    printf("\n");
    return 0;

}