#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long mod = 1e9+7;
long long r = 0, g = 0, b = 0;

long long solve(long long sum, long long a){
    long long count = 0;
    if(a == r) count++;
    if(a == g) count++;
    if(a == b) count++;

    if(a == r){
        r++;
    }
    else{
        if(a == g){
            g++;
        }
        else{
            b++;
        }
    }

    sum = (sum*count)%mod;
    return sum;
}

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    
    long long sum = 1;

    for(long long i = 0; i < n; i++){
        sum = solve(sum, a[i]);
    }

    cout << sum << endl;
    return 0;
}