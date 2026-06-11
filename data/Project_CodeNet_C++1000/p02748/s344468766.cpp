#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b,m;
    cin >> a >> b >> m;
    int p[a],q[b],x[m],y[m],c[m];
    for(int i = 0; i < a; i++){
        cin >> p[i];
    }
    for(int i = 0; i < b; i++){
        cin >> q[i];
    }
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i] >> c[i];
    }
    int ans = 1000000000;
    for(int i = 0; i < m; i++){
        ans = min(ans,p[x[i]-1] + q[y[i]-1] - c[i]);
    }
    sort(p, p+a);
    sort(q, q+b);
    ans = min(ans,p[0]+q[0]);
    cout << ans << endl;
    return 0;
}