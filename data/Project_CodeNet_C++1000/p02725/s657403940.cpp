// C - Traveling Salesman around Lake
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ma = 0;
    for(int i=0; i<n-1; i++){
        ma = max(abs(a[i]-a[i+1]), ma);
    }
    if(a[0] == 0) ma = max(k-a[n-1], ma);
    else ma = max(a[0]+(k-a[n-1]), ma);
    int ans = k-ma;
    cout << ans << endl;
    return 0;
}