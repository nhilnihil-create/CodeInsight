#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int num1,num2;
    int a[5],b[5];
    while(~scanf("%d",&a[1])){
          for(int i=2;i<=4;i++){
            scanf("%d",&a[i]);
          }
          for(int i=1;i<5;i++){
            scanf("%d",&b[i]);
          }
          num1=0;
          num2=0;
          for(int i=1;i<=4;i++){
            if(a[i]==b[i]) num1++;
            for(int j=0;j<=4;j++){
                if(i!=j){
                    if(a[i]==b[j]) num2++;
                }
            }
          }
          printf("%d %d\n",num1,num2);

    }
return 0;
}