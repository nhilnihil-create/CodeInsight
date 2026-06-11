#include <iostream>
#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

long long ncr(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
ll mod(ll a,ll b,ll m){
    if(b==0)return 1;
    if(b%2==0){
        ll y =  mod(a,b/2,m);
        return (y*y)%m;
    }
    else{
        return ((a%m)*mod(a,b-1,m))%m;
    }
}

ll modinv(ll a,ll m){
return mod(a,m-2,m);
//works only for prime m.
//else calculate phi(m)-1.
}



int main()
{
    string s;
    cin>>s;
    if(s=="Sunny")cout<<"Cloudy";
    else if(s=="Cloudy")cout<<"Rainy";
    else cout<<"Sunny";

    return 0;
}
