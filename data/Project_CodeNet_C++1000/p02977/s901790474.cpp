#include<bits/stdc++.h>
using namespace std;
int n;
int ask(int x){
    if(x&1) return x+n;
    return x;
}
int main(){
    scanf("%d",&n);
    if(n<3) return printf("No\n"),0;
    int y=n,flag=0;
    while(y>1){
    flag|=y&1;
    y>>=1;
    }
    if(!flag) return printf("No\n"),0;
    printf("Yes\n");
    printf("%d %d\n",n+1,n+2);
    for(int i=2;i<n;i+=2){
    printf("%d %d\n",1,i);
    printf("%d %d\n",i,i+1);
    printf("%d %d\n",1,i+n+1);
    printf("%d %d\n",i+n,i+n+1);
    }
    if(n%2==0){
    for(int i=2;i<n;i++){
        if(((n^1^i)<n)&&((n^1^i)>1)&&(n^1^i)!=i){
        printf("%d %d\n",ask(i),n);
        printf("%d %d\n",ask(n^1^i),2*n);
        return 0;
        }
    }
    }
}
