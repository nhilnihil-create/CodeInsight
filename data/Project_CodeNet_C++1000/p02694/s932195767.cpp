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
    int X;
    cin >> X;
    int money = 100, c = 0;
    while(money < X){
        money += money/100;
        c++;
    }
    cout << c << endl;
    return 0;
}
