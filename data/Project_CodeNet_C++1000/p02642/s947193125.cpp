#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<bool> flag(a.back()+1, true);
    for(int i = 0; i < n; i++) if(flag[a[i]]) for(int j = 2*a[i]; j < a.back()+1; j += a[i])
        flag[j] = false;
    if(n == 1) {
        ans = 1;
    } else if(n == 2){
        if(a[0] == a[1]) ans = 0;
        else if(a[1] % a[0] == 0) ans = 1;
        else ans = 2;
    } else {
        if(flag[a[0]] && (a[0] != a[1])) ans++;
        for(int i = 1; i < n-1; i++) if(flag[a[i]] && (a[i-1] != a[i]) && (a[i] != a[i+1])) ans++;
        if(flag[a[n-1]] && (a[n-2] != a[n-1])) ans++;
    }
    cout << ans << endl;
    return 0;
}
