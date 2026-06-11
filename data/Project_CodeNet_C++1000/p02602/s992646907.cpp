#include <stdio.h>
#include <string.h>
int main()
{   
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n+5];
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=k+1;i<=n;i++){
        if (arr[i-k]<arr[i]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}