#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, x[200100], y[200100], i, ans=-1, distx, disty;
    cin >> n;
    for(i=0;i<n;i++){
        long long tmpx, tmpy;
        cin >> x[i] >> y[i];
        tmpx=x[i];tmpy=y[i];
        x[i]-=tmpy;
        y[i]+=tmpx;
    }
    sort(x, x+n);
    sort(y, y+n);
    distx=x[n-1]-x[0];
    disty=y[n-1]-y[0];
    ans=max(distx, disty);
    cout << ans <<endl;
    return 0;
}
