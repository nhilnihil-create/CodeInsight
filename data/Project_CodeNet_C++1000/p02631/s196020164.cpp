#include <bits/stdc++.h>

using namespace std;

//FILE *fi=freopen("1.txt","r",stdin);

int n,a[200001],s=0;

void nhap()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        s^=a[i];
    }
    for (int i=1;i<=n;++i)
    {
        cout<<(s^a[i])<<" ";
    }
}

int main()
{
    nhap();
    return 0;
}
