#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
int n,m,k;

int main(){
    scanf("%d",&n);
    if((n&(n-1))==0){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n",n+1,n+2,n+2,n+3,n+3,1,1,2,2,3);
    for(int i=4;i<n;i+=2){
        printf("%d %d\n",1,i);
        printf("%d %d\n",i,i+1);
        printf("%d %d\n",1,n+i+1);
        printf("%d %d\n",n+i+1,n+i);
    }
    if(n%2==0){
        m=n^1; k=0;
        while((m>>k)!=1) k++;
        k=1<<k; m^=k;
        printf("%d %d\n%d %d\n",k,n,n+m,n+n);
    }
}