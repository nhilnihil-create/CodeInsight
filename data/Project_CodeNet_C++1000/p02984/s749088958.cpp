#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[100009]={0},b[100009]={0};
int main()
{
    int n,i;
    long long sum=0,s=0,f;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int n1;
        scanf("%d",&n1);
        a[i]=2*n1;
        s+=n1;
    }
    sum+=a[n];
    for(i=3;i<n;i=i+2){
        sum+=a[i];
    }
    f=s-sum;
    b[1]=a[1]-f;
    for(i=2;i<n;i++)
        b[i]=a[i-1]-b[i-1];
    b[n]=a[n]-b[1];
    for(i=1;i<=n;i++){
        if(i>1)
            printf(" ");
        printf("%d",b[i]);
    }

}
