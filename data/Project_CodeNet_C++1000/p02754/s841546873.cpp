#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, a, b;
    cin>> n >> a >> b;

    ll ans;
    ans = n/(a+b)*a;

    n = n%(a+b);
    
    if(n-a >= 0){
        ans += a;
    }else{
        ans += n;
    }

    cout<< ans << endl;

    return 0;
}