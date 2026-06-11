#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i,j;
    double a[10],b[10];
    double c=0;
    scanf("%d",&n);
    for (i=0;i<n;i++)
        scanf("%lf%lf",&a[i],&b[i]);
    for (i=0;i<n-1;i++)
        for (j=i+1;j<n;j++)
            c=c+sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]))*2/n;
    printf("%.10f",c);
    return 0;
}