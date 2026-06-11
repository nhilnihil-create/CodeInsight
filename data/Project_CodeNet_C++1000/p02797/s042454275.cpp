#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<map>
int a[100010];
const int t=1000000000;
using namespace std;
int main(){
    int n,m,sum;
    scanf("%d%d%d",&n,&m,&sum);
    for (int i=0;i<m;i++){
        a[i]=sum;
    }
    if (sum!=t){
    for (int j=m;j<n;j++){
        a[j]=sum+1;
    }
}
    else {
        for (int j=m;j<n;j++){
        a[j]=1;
    }

    }
    for (int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}