#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n), sum(n+1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    ll min_diff = 4e18;
    for(int i = 0; i < n; i++){
        if(min_diff > abs(sum[n]-2*sum[i])){
            min_diff = abs(sum[n]-2*sum[i]);
        }
    }
    cout << min_diff << endl;
    return 0;
}