#include <bits/stdc++.h>

using namespace std;

//FILE *fi=freopen("1.txt","r",stdin);

int m,d,dem=0;

void process()
{
    for (int i=1;i<=m;++i)
    {
        for (int j=1;j<=d;++j)
        {
            if (j%10>=2 && j/10>=2 && (j%10)*(j/10)==i) dem++;
        }
    }
    cout<<dem;
}

int main()
{
    scanf("%d %d",&m,&d);
    process();
    return 0;
}
