#include <bits/stdc++.h>
using namespace std;
int n;
long long x[200001],y[200001],yp[200001],xp[200001],mnx=0x3f3f3f3f3f3f3f3f,mny=0x3f3f3f3f3f3f3f3f,mxx=-0x3f3f3f3f3f3f3f3f,mxy=-0x3f3f3f3f3f3f3f3f,ans[200001],out;
int main() {
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>x[i]>>y[i];
        xp[i]=x[i]-y[i];
        mnx=min(mnx,xp[i]);
        mxx=max(mxx,xp[i]);
        yp[i]=x[i]+y[i];
        mny=min(mny,yp[i]);
        mxy=max(mxy,yp[i]);
    }
    for (int i=0; i<n; i++) {
        long long a=max(abs(xp[i]-mnx),abs(mxx-xp[i])),b=max(abs(yp[i]-mny),abs(mxy-yp[i]));
        ans[i]=max(a,b);
    }
    for (int i=0; i<n; i++) {
        out=max(out,ans[i]);
    }
    cout<<out<<'\n';
}