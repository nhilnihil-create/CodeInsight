#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    
    bool cekNum = false;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if(num == (i*j)){
                cekNum = true;
            }
        }
    }
    
    if(cekNum){
        puts ("Yes");
    }else{
        puts ("No");
    }
    
    return 0;
}