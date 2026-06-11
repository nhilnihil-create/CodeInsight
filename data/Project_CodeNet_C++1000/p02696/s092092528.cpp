#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isprime(int n){
    double rootn = sqrt(n);
    if (n < 2){
        return false;
    }
    else if (n == 2){
        return true;
    }
    else if (n % 2 == 0){
        return false;
    }
    else{
        for(int i = 3; i <= rootn; i += 2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}


signed main(){
    int A, B, N;
    cin >> A >> B >> N;

    int r = B-1;
    if(r > N){
        r = N;
    }
    cout << A*r / B << endl;

    return 0;
}