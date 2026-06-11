#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, cnt = 0; cin >> n; int a[n]; for(int& i : a) cin >> i;
    for(int i = 1; i < n-1; i++) {
        if(a[i] < a[i-1] && a[i] > a[i+1]) cnt++;
        if(a[i] > a[i-1] && a[i] < a[i+1]) cnt++;
    }    
    cout << cnt;
}