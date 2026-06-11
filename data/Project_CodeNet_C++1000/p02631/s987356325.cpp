#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    ll s = a[0];
    for(int i=1;i<n;i++) s ^= a[i];

    for(int i=0;i<n;i++){
        ll t = s^a[i];
        cout << t << " ";
    }
    printf("\n");
    return 0;
}