#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    ll n;
    cin >> n;
    ll ans=0;
    for(int i=0; i<n; ++i)
        ans += i;
    cout << ans;
}