#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, cur = 0; cin >> n; string s; cin >> s;
    int a[n-1], cnt[3]={};
    for(int i = 0; i < n-1; i++) {
        a[i] = abs(s[i+1] - s[i]);
        cnt[a[i]]++;
    }

    int mul = 1, res = 0;
    if(cnt[1] == 0) {
        mul++;
        for(int &x : a) x >>= 1;
    }

    for(int i = 0; i < n-1; i++) if(((n-2) & i) == i) res ^= a[i];
    cout << (res & 1) * mul; 
}