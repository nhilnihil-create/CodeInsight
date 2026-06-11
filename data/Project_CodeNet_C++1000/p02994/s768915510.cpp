#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, l, sum = 0; cin >> n >> l;
    int a[n];
    for(int i = 0; i < n; i++) a[i] = l + i;
    int mn = 1e9;
    for(int i : a) {
        sum += i;
        if(abs(i) < abs(mn)) {
            mn = i;
        }
    }    
    cout << sum - mn;
}