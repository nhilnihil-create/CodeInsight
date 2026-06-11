#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    vector<ll> t(2),a(2),b(2);
    for (int i=0;i<2;i++) cin >> t[i];
    for (int i=0;i<2;i++) cin >> a[i];
    for (int i=0;i<2;i++) cin >> b[i];
    if (a[0]<b[0]) {
        swap(a[0],b[0]);
        swap(a[1],b[1]);
    }
    a[0]=a[0]-b[0];
    b[0]=0;
    a[1]=a[1]-b[1];
    b[1]=0;
    for (int i=0;i<2;i++) {
        a[i]*=t[i];
        b[i]*=t[i];
    }
    ll p=a[0]+a[1];
    if (p==0) cout << "infinity" << endl;
    else if (p>0) cout << 0 << endl;
    else {
        ll s=a[0]/(-p),t=a[0]%(-p);
        if (t==0) cout << 2*s << endl;
        else cout << 2*s+1 << endl;
    }
}