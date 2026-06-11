#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n, m, total = 0, ok = 0;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) total += a[i];
    for(int i = 0; i < n; i++){
        if(4*a[i]*m >= total) ok++;
    }
    if(ok >= m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
