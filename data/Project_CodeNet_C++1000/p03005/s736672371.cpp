///******* In the name of Allah *******///

#include<bits/stdc++.h>
using namespace std;

void Ok()
{
    long int a[113],b,c,d,e,f,g,t,i,j,k,l,m,n,r,sum,ans_1,ans_2,ans_3,cnt,Max = 0,Min = 999;
    double aa,bb,cc,dd,ee;
    char aaa[1013],bbb[1013],ccc[1013];

    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        a[i] = 1;
    }

    ans_1 = (n - k);
    a[1] += ans_1;

    for(i=1;i<=k;i++)
    {
        Max = max(Max,a[i]);
        Min = min(Min,a[i]);
    }
    ans_2 = Max - Min;
    cout<<ans_2<<endl;

    return;
}

int main()
{
    Ok();

    return 0;
}
