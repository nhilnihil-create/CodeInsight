#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long int> a(n+1);
    for(int i=0; i<=n; i++){
        cin >> a[i];
    }

    if(n == 0){
        if(a[0] == 1) cout << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }

    if(a[0] != 0){
        cout << -1 << endl;
        return 0;
    }

    vector<long long int> sa(n+1);
    for(int i=1; i<=n; i++){
        sa[i] = sa[i-1] + a[i];
    }

    long long int ans = 1;
    vector<long long int> b(n+1);
    b[0] = 1;
    for(int i=1; i<=n; i++){
        b[i] = min(2 * b[i-1] - a[i], sa[n] - sa[i]);
        if(b[i] < 0){
            cout << -1 << endl;
            return 0;
        }
        ans += a[i] + b[i];
    }
    cout << ans << endl;
    return 0;
}
