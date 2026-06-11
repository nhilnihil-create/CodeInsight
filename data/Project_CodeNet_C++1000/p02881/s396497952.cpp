#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n;
    cin >> n;
    long long div = INT64_MAX / 2;
    long long div2 = INT64_MAX / 2;
    for(long long i = 2;i < sqrt(n) + 1;i++){
        if(n % i == 0){
            long long t1;
            long long t2;
            t1 = n / i;
            t2 = i;
            if(t1 + t2 < div + div2){
                div = t1;
                div2 = t2;
            }
        }
    }
    if(div != INT64_MAX / 2){
        cout << div + div2 - 2 << endl;
    }else{
        cout << n - 1 << endl;
    }
}