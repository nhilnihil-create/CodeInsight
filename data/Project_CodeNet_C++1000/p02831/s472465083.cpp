#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long

ll euclid(ll x,ll y){
    if(y==0){
        return x;
    }else{
        return euclid(y,x%y);
    }
}

int main(){
    ll a,b;
    cin >> a >> b;
    ll gcd = euclid(max(a,b),min(a,b));
    cout << a*b/gcd << endl;
    return 0;
}
