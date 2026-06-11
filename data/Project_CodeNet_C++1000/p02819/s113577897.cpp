#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

bool isprime(int n){
    for(int i=2; i*i <= n; ++i){
        if(n%i==0)
            return false;
    }

    return true;
}

int main(){
    int n;
    cin >> n;
    for(int i=n; 1; ++i){
        if(isprime(i)){
            cout << i;
            break;
        }
    }
}