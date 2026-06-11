#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define oo 1000000000000000000LL
using namespace std;


void _sol(){
    ll x = 1000;
    ll n; cin >> n;
    ll cnt =1;
    while(cnt * x < n) cnt++;
    cout << cnt*x - n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) _sol();
}
