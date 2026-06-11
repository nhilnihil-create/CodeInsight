#include<cstdio>
using namespace std;
int m,n;
int main(){
    scanf("%d%d",&n,&m);
    int l1=1,r1=l1+m,l2=r1+1,r2=l2+m-1;
    while(true){
        if(l1>=r1) break;
        printf("%d %d\n",l1,r1);
        if(l2>=r2) break;
        printf("%d %d\n",l2,r2);
        l1++,l2++;
        r1--,r2--;
    }
    return 0;
}
