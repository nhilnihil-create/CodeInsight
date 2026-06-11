#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n; cin >> n; 
    int a[n];
    for(int &i : a) cin >> i;
    sort(a, a + n, greater<int>());

    int j = n - 1;
    for(int i = 1; i < n; i++) if(a[i] < 0) {j = i; break;}

    int ans = 0;
    for(int i = 0; i < j; i++) ans += a[i];
    for(int i = j; i < n; i++) ans -= a[i];

    cout << ans << '\n';
    for(int i = 1; i < j; i++) cout << a[j] << " " << a[i] << '\n', a[j] -= a[i];
    for(int i = j; i < n; i++) cout << a[0] << " " << a[i] << '\n', a[0] -= a[i];     
}