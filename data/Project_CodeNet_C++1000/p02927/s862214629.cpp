
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,d;
    scanf("%d%d",&m,&d);
    int num = 0;
    for(int i = 1;i <= m;i++){
        for(int j = 22;j <= d;j++){
            if(j%10<2) continue;
            if((j%10)*(j/10) == i){
               // cout<<i<<" "<<j<<endl;
                num++;
            }
        }
    }
    printf("%d\n",num);
    return 0;
}
