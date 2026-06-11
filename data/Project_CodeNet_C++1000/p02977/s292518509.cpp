#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if((n&(n-1)) == 0){
        printf("No\n");
        return 0;
    }

    printf("Yes\n");
    int line = (n%4==3? n : n-(n%4)-1);
    printf("%d %d\n",line,n+1);
    for(int i=1; i<line; i++){
        printf("%d %d\n",i,i+1);
        printf("%d %d\n",n+i,n+i+1);
    }

    if(n%4 == 0){
        int msb = 1<<(int)log2(n);
        printf("%d %d\n",n,msb);
        printf("%d %d\n",2*n,n-msb+1);
    }
    else if(n%4 == 1){
        printf("%d %d\n",1,n);
        printf("%d %d\n",n-1,n);
        printf("%d %d\n",n+1,n+n-1);
        printf("%d %d\n",n+n-1,n+n);
    }
    else if(n%4 == 2){
        printf("%d %d\n",1,n-1);
        printf("%d %d\n",n-1-1,n-1);
        printf("%d %d\n",n+1,n+n-1-1);
        printf("%d %d\n",n+n-1-1,n+n-1);
        printf("%d %d\n",n-1,n);
        printf("%d %d\n",2,n+n);
    }
}
