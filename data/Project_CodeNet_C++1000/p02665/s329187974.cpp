#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll INF = 10000000000000;
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i = 0; i < n+1; i++) cin >> a[i];

    vector<ll> ma(n+1);

    ll num_m = 1;
    for(int i = 0; i < n+1; i++){
        ma[i] = num_m - a[i];
        if(ma[i] < 0){
            cout << -1;
            return 0;
        }
        num_m = min(ma[i]*2, INF);
    }
    
    ll num_before = a[n];

    vector<ll> num_b(n);
    for(int i = n-1; i >= 0 ; i--){
        num_b[i] = min(num_before, ma[i]);
        num_before = num_b[i] + a[i];
    }

    ll num_all=a[n];
    for(int i= 0; i < n; i++){
        num_all += num_b[i] + a[i];
    }
    cout << num_all;
}