#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[100009]={0},b[100009]={0};
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int n1;
        scanf("%d",&n1);
        a[n1]=i;
    }
    for(i=1;i<=t;i++){
        if(i>1)
            printf(" ");
        printf("%d",a[i]);
    }
    return 0;
}
