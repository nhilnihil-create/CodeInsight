#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,k;
    cin>>n>>k;
    ll rm = n%k;
    ll res = min(rm,abs(rm-k));
    cout<<res;
}
