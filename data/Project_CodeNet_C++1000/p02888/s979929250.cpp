#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,a[2009]={0},j,k,tot=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int n1;
        scanf("%d",&n1);
        a[i]=n1;
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n-2;i++){
        for(j=i+1;j<=n-1;j++){
            for(k=j+1;k<=n;k++){
                if(a[i]+a[j]>a[k])
                    tot++;
                else
                    break;
            }
        }
    }
    printf("%d\n",tot);
}
