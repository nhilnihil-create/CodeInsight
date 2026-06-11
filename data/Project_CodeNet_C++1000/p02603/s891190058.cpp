#include <bits/stdc++.h>

using namespace std;

//FILE *fi=freopen("1.txt","r",stdin);

int n,a[81];

void nhap()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }
}

void process()
{
    int i=1;
    long long s=1000;
    while (i<n)
    {
        int j=i+1;
        while (j<=n && a[j]>=a[j-1])
            j++;
        j--;
        long long t=s/a[i];
        s=s-t*a[i]+t*a[j];
        i=j+1;
    }
    cout<<s;
}

int main()
{
    nhap();
    process();
    return 0;
}
