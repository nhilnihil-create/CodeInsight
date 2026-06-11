#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(ll X){
    for(ll i=2;i*i<=X;i++){
        if(X%i==0)return false;
    }
    return true;
}

int main()
{
    ll X;
    cin >> X;
    ll res=0;
    while(true){
        bool prime = isPrime(X);
        if(prime){
            cout<<X;return 0;
        }
        ++X;
    }
}