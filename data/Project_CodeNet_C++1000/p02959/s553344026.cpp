#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int a[n+1], b[n];
    for(int i = 0; i < n+1; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        int x = min(a[i], b[i]);
        ans += x;
        a[i] -= x;
        b[i] -= x;
        int y = min(a[i+1], b[i]);
        ans += y;
        a[i+1] -= y;
    }
    cout << ans << endl;
    return 0;
}