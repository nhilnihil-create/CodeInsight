#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, k;
    cin>> n >> k;
    while(n>k){
        ll x = n/k;
        n=abs(n-x*k);
    }
    while(n>abs(n-k)){
        n = abs(n-k);
    }
    cout<< n <<endl;
    return 0;
}