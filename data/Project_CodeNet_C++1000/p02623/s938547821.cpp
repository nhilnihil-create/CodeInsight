#include <bits/stdc++.h>
using namespace std;
long long n,m,k,i,j,c,d,mx,s,x,y,a[200001],b[200001],a1[200001],b1[200001];
int main() {
    cin >> n >> m >> k;
    for (i=1; i<=n; i++)
        cin >> a[i];
    for (i=1; i<=m; i++)
        cin >> b[i];

    for (i=1; i<=n; i++)
    {
        s+=a[i];
        a1[i]=s;
    }
    s=0;
    for (i=1; i<=m; i++)
    {
        s+=b[i];
        b1[i]=s;
    }

a1[0]=0; b1[0]=0;
    for (i=0; i<=n; i++)
    {
        if (k>=a1[i])
        x=k-a1[i];
        else
        break;
        d=1;
        c=m;

        while ( d<=m && c>=0 && c>d)
        {

            j=(c+d)/2;
            if (b1[j]==x){c=j;break;}
            if (b1[j]>x)
            c=j-1;
            else
            d=j+1;

        }
        if (b1[c]>x)j=c-1;else j=c;

        if (b1[1]>x)
            j=0;
        if (i+j>mx)
            mx=i+j;

    }
    cout<<mx;


}
