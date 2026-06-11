#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 998244353

int main() {
    int n;cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(a[0]!=0){
        cout << 0 << endl;
        return 0;
    }
    if(n==2){
        if(a[1]!=1){
        cout << 0 << endl;
        return 0;
        }
    }

    sort(a.begin(),a.end());
    vector<int> b(a[n-1]+1);
    for(int i = 1; i < n; i++) {
        b[a[i]]++;
    }
    if(b[0]>0){
        cout << 0 << endl;
        return 0;
    }

    ll ans=1;
    for(int i = 2; i < a[n-1]+1; i++) {
        for(int j = 0; j < b[i]; j++) {
            ans *= b[i-1];
            ans %= INF;
        }
    }
    cout << ans << endl;

    return 0;
}