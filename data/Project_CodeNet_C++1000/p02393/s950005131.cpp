#include <stdio.h>
int main (){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    for(int i = 0;;i++){
        for(int j = 0;;j++){
            if(a>b){
                int k = a;
                a = b;
                b = k;
            }
        else if(b>c){
            int l = b;
            b = c;
            c = l;
            }
        else{
            a = a;
            b = b;
            c = c;
            }
    break;
        }
        if(a <= b && b <= c)
        break;
    }
    printf("%d %d %d\n",a,b,c);
    return 0;
}
