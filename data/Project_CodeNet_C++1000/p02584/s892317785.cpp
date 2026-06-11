#include "bits/stdc++.h"
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long x , k , d;
    cin >> x >> k >>d;

    x=abs(x);
    if(x/d>=k){
        cout<<x-k*d<<endl;
    }
    else{
        long long  ans=x%d;
        long long  f=k-x/d;
        if(f&1)ans=abs((d-ans));
        cout<<ans<<endl;
    }
}

