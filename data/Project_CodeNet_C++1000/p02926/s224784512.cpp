#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const long double pi= 3.1415926535897932384626;
const long double eps = 1e-9;


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin>>n;
    long double x[n],y[n];
    long double ans = 0;
    array<long double,3> d[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        d[i] = {atan2(y[i],x[i]),x[i],y[i]};
        ans = max(ans, x[i]*x[i] + y[i]*y[i]);
    }
    sort(d,d+n);
    for(int i=0;i<n;i++){
        long double dx = 0, dy = 0;
        for(int j=0;j<n;j++){
            dx += d[(i+j)%n][1], dy += d[(i+j)%n][2];
            ans = max(ans,dx*dx + dy*dy);
        }
    }
    
    ans = sqrt(ans);
    cout << ans << endl;

}