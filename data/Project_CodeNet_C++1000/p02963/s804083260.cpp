#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int s;
    cin >> s;

    long long int a, b, c, d;
    long long int lower = 0, upper = 1e9;
    while(upper - lower > 1){
        long long int mid = (upper + lower) / 2;
        if(mid * mid <  s) lower = mid;
        if(mid * mid >= s) upper = mid;
    }
    a = upper;
    d = upper;
    s = a * d - s;

    if(s == 0){ b = 0; c = 0; }
    else{
        for (long long int i=1; i*i<=s; i++){
            if (s % i == 0){
                b = i;
                c = s / i;
            }
        }
    }

    cout << 0 << " " << 0 << " "
         << a << " " << b << " "
         << c << " " << d << endl;
    return 0;
}