#include <bits/stdc++.h>
using namespace std;
int x,n,a[101],i,y,mx,ans,ans1;
bool b[101];
int main() {
    cin >> x >> n;
    for (i=1; i<=n; i++)
    {
        cin >> a[i];
        y=a[i];
        b[y]=true;
        mx=max(mx,a[i]);
    }
    for (i=x; i>=0; i--)
        if (b[i]==false)
        {
            ans=i;
            break;
        }

    for (i=x+1; i<=mx+1; i++)
        if (b[i]==false)
        {
            ans1=i;
            break;
        }
    if (x-ans>ans1-x && ans1-x>=0) cout<<ans1;
    else
        cout<<ans;
}
