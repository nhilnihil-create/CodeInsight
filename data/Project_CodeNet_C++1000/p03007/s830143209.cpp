#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n == 2){
        long long a, b;
        cin >> a >> b;
        cout << (max(a, b) - min(a, b)) << endl;
        cout << max(a, b) << " " << min(a, b) << endl;
        return 0;
    }
    vector<long long> v(n);
    long long ans = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        ans += abs(v[i]);
    }
    sort(v.begin(), v.end());
    bool ex1 = false, ex2 = false;
    if(v[0] >= 0){
        ans -= abs(v[0]) + abs(v[1]);
        ans += abs(v[0] - v[1]);
        ex1 = true;
    }
    if(v[n-1] < 0){
        ans -= abs(v[n-1]) + abs(v[n-2]);
        ans += abs(v[n-1] - v[n-2]);
        ex2 = true;
    }
    cout << ans << endl;
    if(ex1){
        cout << v[0] << " " << v[1] << endl;
        v[0] -= v[1];
    }
    if(ex2){
        cout << v[n-1] << " " << v[n-2] << endl;
        v[n-1] -= v[n-2];
    }
    for(int i = 1; i < n-1; i++){
        if(ex1 && i == 1) continue;
        if(ex2 && i == n-2) continue; 
        if(v[i] < 0){
            cout << v[n-1] << " " << v[i] << endl;
            v[n-1] -= v[i];
        }
        else{
            cout << v[0] << " " << v[i] << endl;
            v[0] -= v[i];
        }
    }
    cout << v[n-1] << " " << v[0] << endl;
    return 0;
}