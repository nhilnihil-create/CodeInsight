#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(200005), cnt(200005);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll sum = 0;
    for(int i = 0; i < 200005; i++){
        if(cnt[i] >= 2){
            sum += cnt[i]*(cnt[i]-1)/2;
        }
    }
    for(int i = 0; i < n; i++){
        cout << sum - (cnt[a[i]] - 1) << endl;
    }
}