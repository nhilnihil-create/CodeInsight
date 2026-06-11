#include <cstdio>
#include <map>
using namespace std;
int main(){
    int n,m;
    for(;;){
        scanf("%d\n",&n);
        if(n==0) break;
        int cs[256];
        for(int i=0;i<=255;i++){
            cs[i]=-1;
        }
        char a,b;
        for(int i=0;i<n;i++){
            scanf("%c %c\n",&a,&b);
            cs[a]=b;
        }
        scanf("%d\n",&m);
        for(int i=0;i<m;i++){
            scanf("%c\n",&a);
            printf("%c",cs[a]>=0?cs[a]:a);
        }
        printf("\n");
    }
}