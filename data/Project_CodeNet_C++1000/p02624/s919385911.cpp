#include <bits/stdc++.h>
using namespace std;


int main() {
     int n;
     cin >> n;
     long long ans = 0;
     for(int i = 1;i <= n;i++){
         long long y = n/i;
         ans += i * y * (y + 1) / 2;
     }
     cout << ans;
}