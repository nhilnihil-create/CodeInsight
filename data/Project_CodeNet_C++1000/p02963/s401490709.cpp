#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll s;cin>>s;

    ll v = 1e9;
    ll x = (v - s%v)%v;
    ll y = (s+x)/v;

    cout<<"0 0 1000000000 1 "<<x<<" "<<y;
}