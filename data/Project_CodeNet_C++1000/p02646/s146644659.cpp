#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,v,w,t;
    cin>>a>>v>>b>>w>>t;
    ll d1 = abs(a - b);
    ll d2 = (v - w) * t;
    cout<<(d1 <= d2 ? "YES" : "NO")<<"\n";
}