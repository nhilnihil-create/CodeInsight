#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 2100;


int main(){
    int n; cin >> n;
    vector<ll> l;
    for(int i=0; i<n; i++){
        ll tmp; cin >> tmp;
        l.push_back(tmp);
    }

    vector<int> cum(MAX, 0), c(MAX+1, 0);
    for(int i=0; i<n; i++) c[l[i]]++;
    for(int i=0; i<MAX; i++) cum[i+1] = cum[i] + c[i]; // 累積和

    ll ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) continue;
            int left = abs(l[i] - l[j]) + 1;
            int right = l[i] + l[j];
            int count = cum[right] - cum[left];
            if(left <= l[i] && l[i] < right) count--;
            if(left <= l[j] && l[j] < right) count--;
            ans += max(count, 0);
        }
    }

    cout << ans/6 << endl;
    return 0;
}