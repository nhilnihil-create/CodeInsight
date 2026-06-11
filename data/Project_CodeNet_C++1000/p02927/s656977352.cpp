#include<bits/stdc++.h>
using namespace std;
int main(){
    int d,m;
    scanf("%d%d",&m,&d);
    int cnt=0;
    for(int i=1;i<=m;i++){
        for(int j=2;j<10;j++){
            for(int k=2;k<10;k++){
                if(j*k==i&&j*10+k<=d)
                    cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
