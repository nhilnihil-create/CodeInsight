#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool isPrime(int x){
    ll up = sqrt(x);
    for(ll i=2;i<up;i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(){
    ll x;
    cin >> x;
    while(true){
        if(isPrime(x)){
            cout << x << endl;
            break;
        }
        x++;
    }
    return 0;
}