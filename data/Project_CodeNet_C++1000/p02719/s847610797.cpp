#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    ll n, k;
    cin>>n>>k;
    ll ans;
    ans = min(n%k, abs(n%k-k));
    cout<<ans;
    return 0;
}