#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; scanf("%d %d", &n, &k);
    int c = (n-1)*(n-2)/2-k;
    if(c < 0) printf("%d",-1);
    else{
        printf("%d\n",c+(n-1));
        for(int i=1; i<=n-1;  i++) printf("%d %d\n",i,n);
        for(int i=1; i<=n-1; i++) for(int j=i+1; j<=n-1; j++){
            if(!c--) return 0; printf("%d %d\n",i,j);
        }
    }
}