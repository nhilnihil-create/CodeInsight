#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    LL m, cnt = 0, sum = 0, d, c; cin >> m; 
    while(m--) {
        cin >> d >> c;
        sum += d * c, cnt += c;
    }    
    cout << (cnt - 1) + (sum-1) / 9;
}