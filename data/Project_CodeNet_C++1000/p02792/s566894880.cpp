#include <cstdio>



int count[10][10];
int N;


int main(){
    scanf("%d",&N);

    for(int i=1;i<=N;i++){
        int lsb=i%10,msb;
        int temp=i;
        while(temp>=10) temp/=10;
        msb=temp;
        count[msb][lsb]++;
    }

    int ans=0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ans+=(count[i][j]*count[j][i]);
        }
    }

    printf("%d\n",ans);


    return 0;
}