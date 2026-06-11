#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

ll n, m, k, a[202020], b[202020], c[404040];

int main(){
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++) cin >> a[i], a[i] += a[i-1];
    for(int i=1; i<=m; i++) cin >> b[i], b[i] += b[i-1];
    
    int j = m, mx = 0;
    for(int i=0; i<=n; i++){
        if(a[i] > k) break;
        while(a[i]+b[j] > k) j--;
        mx = max(mx, i+j);
    }
    cout << mx;
}