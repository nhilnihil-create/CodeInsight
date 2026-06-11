#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 0; i < n+1; i++) cin >> a[i];

    ll dl[n+1],dr[n+2];
    dl[n] = dr[n] = a[n];
    dr[n+1] = 0;
    for(int i = n-1; i >= 0; i--){
        dl[i] = (dl[i+1]+1)/2+a[i];
        dr[i] = dr[i+1]+a[i];
    }

    if(dl[0] > 1) cout << -1 << endl;
    else {
        ll ans = 0;
        ll E = 1;
        for(int i = 0; i < n+1; i++){
            ans += E;
            E -= a[i];
            E = min(E*2,dr[i+1]);
        }
        cout << ans << endl;
    }
    return 0;
}