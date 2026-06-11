#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,n1,n2,m=1,i;
    scanf("%d",&n);
    while((m<<1)<=n)m<<=1;
    if(n==m){printf("No");return 0;}
    n1=n+1;n2=n<<1;
    printf("Yes\n1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n1,n1,n+2,n+2,n+3);
    for(i=4;i<n;i+=2)printf("%d %d\n%d %d\n%d %d\n%d %d\n",n1,i,i,i|1,n1,n+(i|1),n+(i|1),n+i);
    if(!(n&1)){
        printf("%d %d\n",m,n);
        if(n==m+2)printf("3 %d\n",n2);
        else printf("%d %d\n",n2-m+1,n2);
    }
    return 0;
}