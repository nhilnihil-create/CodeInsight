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
    int K, A, B;
    cin >> K >> A >> B;
    int q = A/K;
    if((A <= q*K+K && q*K+K <= B) || (A <= q*K && q*K <= B)){
        cout << "OK" << endl;
    }
    else{
        cout << "NG" << endl;
    }
    return 0;
}