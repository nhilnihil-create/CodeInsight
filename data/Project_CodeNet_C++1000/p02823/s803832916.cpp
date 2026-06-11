#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,a,b; cin >> n >> a >> b;
    if((b-a)%2) cout << min(a+(b-a-1)/2,n-b+1+(b-a-1)/2) << endl;
    else cout << (b-a)/2 << endl;
}