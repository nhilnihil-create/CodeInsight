#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //good luck kittu!
    ll a, b, n, t1, t2; cin>>a>>b>>n;
    ll x = min(b-1, n);
    t1 = (a*x)/b;
    t2 = x/b;
    t2 *= a;
    cout<<t1-t2<<"\n";
    return 0;
}