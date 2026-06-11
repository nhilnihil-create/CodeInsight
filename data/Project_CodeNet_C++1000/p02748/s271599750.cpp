#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int A,B,M,i,minim,j,sum,min2;
    cin>>A>>B>>M;
    int a[A+5],b[B+5],c[M+5],x[M+5],y[M+5],total[M+5];
    for(i=1; i<=A; i++)
        cin>>a[i];
    for(i=1; i<=B; i++)
        cin>>b[i];
    for(i=1; i<=M; i++)
    {
        cin>>x[i]>>y[i]>>c[i];
    }
    min2=a[x[1]]+b[y[1]]-c[1];
    for(i=1; i<=M; i++)
    {
        total[i]=a[x[i]]+b[y[i]]-c[i];
        if(total[i]<min2)
            min2=total[i];

    }
    sort(a+1,a+A+1);
    sort(b+1,b+B+1);
    minim=a[1]+b[1];

    cout<<min(minim,min2)<<endl;
    return 0;

}


