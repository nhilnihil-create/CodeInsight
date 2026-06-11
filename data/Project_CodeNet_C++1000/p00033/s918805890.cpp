#include <stdio.h>

#include <stack>

int main(void){
    using namespace std;
    stack<int> a,b;
    int n,j,i,ball,flag;
    scanf("%d",&n);
    for(j=0; j<n; j++){
        flag=0;
        for(i=0; i<10; i++){
            scanf("%d",&ball);
            if(a.empty()){
                a.push(ball);
            }else if(a.top() < ball){
                a.push(ball);
            }else if(b.empty()){
                b.push(ball);
            }else if(b.top() < ball){
                b.push(ball);
            }else{
                flag=1;
            }
        }
        while(!a.empty()){
            a.pop();
        }
        while(!b.empty()){
            b.pop();
        }
        if(flag==0){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}