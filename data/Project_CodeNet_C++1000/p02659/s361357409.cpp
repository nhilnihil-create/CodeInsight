#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll a;
    double b;
    cin>>a>>b;
    ll bb=b*100+0.1;
    ll ans=a*bb;
    cout<<ans/100;
}