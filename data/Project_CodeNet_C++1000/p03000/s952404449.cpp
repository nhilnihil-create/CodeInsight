#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, x, y; cin >> n >> x;
    int cnt = 1, cur = 0;
    for(int i = 0; i < n; i++) {
        cin >> y;
        cur += y;
        if(cur <= x) cnt++;
    }    
    cout << cnt;
}