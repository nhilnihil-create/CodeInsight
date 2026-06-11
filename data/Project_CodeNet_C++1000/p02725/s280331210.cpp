#include <bits/stdc++.h>
using namespace std;
int k,n,a[200001],mx,i;
int main() {
    cin >> k >> n;
    for (i=1; i<=n; i++)
    {
        cin >> a[i];
        if (i>1 )
            mx=max(mx,a[i]-a[i-1]);
    }
    mx=max(mx,k-a[n]+a[1]);
    cout<<k-mx;

}
