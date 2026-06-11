#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m;
int sum;
int main(){
    scanf("%d%d%d",&n,&m,&sum);
    int k=0;
    for(int i=0;i<n;i++){
        if(k<m){
            printf("%d ",sum);
            k++;
        }
        else {
            if(sum<1000000000-1){
                printf("%d ",sum+1);
            }
            else printf("%d ",1000000000-3);
        }
    }
    printf("\n");
}