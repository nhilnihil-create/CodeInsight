#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    ll n, k; cin>>n>>k;
    ll h[n];
    for (int i=0; i<n; i++) cin>>h[i];

    sort(h, h+n);

    ll sum = 0;
    for (int i=0; i<n-k; i++)
        sum += h[i];

    cout<<sum<<endl;
}

int main(){
    solve();
    Bye;
}