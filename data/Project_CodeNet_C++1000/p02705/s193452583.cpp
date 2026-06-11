#include <bits/stdc++.h>
using namespace std;
#define ll long long

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


int main(){
    int R;
    cin >> R;
    cout << M_PI * R * 2 << endl;
    return 0;
}