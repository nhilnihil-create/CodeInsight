#include <cstdio>

#define mx 1000006
bool seen[mx];

int main(){
    int k;
    scanf("%d",&k);

    for(int i=0;i<=k;i++) seen[i]=false;

    seen[7%k]=true;
    int rem=7%k;
    int steps=1;
    while(1){
        if(rem==0){
            printf("%d\n",steps);
            break;
        }
        steps++;
        rem=(rem*10+7)%k;
        if(seen[rem]){
            printf("-1\n");
            break;
        }
        seen[rem]=true;
    }
}
