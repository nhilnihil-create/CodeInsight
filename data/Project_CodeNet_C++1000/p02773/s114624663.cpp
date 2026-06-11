#include <bits/stdc++.h>
using namespace std;
int  i,n,j,k,mx,ans[200001];
string a[200001],b[200001];
int main() {
  cin >> n;
  for (i=1; i<=n; i++)
    cin >> a[i];
    a[n+1]="11111111111";
    j=1; k=1;
    sort(a,a+n+1);

    
    for (i=2; i<=n+1; i++)
        if (a[i]!=a[i-1])
    {
        ans[j]=k;

        j=j+k;
        k=1;
    }
    else
    k++;

    for (i=1; i<=n; i++)
        mx=max(mx,ans[i]);

        j=0;
    for (i=1; i<=n; i++)
        if (ans[i]==mx)
    {
        j++;
        b[j]=a[i];
    }
    sort (b,b+j+1);
    for (i=1; i<=j; i++)
        if (i==j)
        cout<<b[i];
    else
        cout<<b[i]<<endl;

}
