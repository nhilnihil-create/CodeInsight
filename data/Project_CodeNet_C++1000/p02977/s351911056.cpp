#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin>>n;
    if (n==(n&-n)) return puts("No"), 0;
    puts("Yes\n1 2\n2 3");
    printf("3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
    for (int i=4;i<n;i+=2){
        printf("%d %d\n%d 1\n1 %d\n%d %d\n",i+1,i,i,i+1+n,i+1+n,i+n);
    }
    if (n%2==0){
        for (int i=20;i>=0;--i)
            if (n>>i&1){
                printf("%d %d\n%d %d\n",n,n-(1<<i),(1<<i)+1+n,n*2);
                break;
            }
    }
}