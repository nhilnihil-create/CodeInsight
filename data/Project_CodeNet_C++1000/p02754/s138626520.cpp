#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    if (n > a+b){
        ll c = n/(a+b);
        n%=(a+b);
        cout << (c*a) + min(a, n);
    }
    else{
        cout<<min(a, n);
    }
    return 0;
}
