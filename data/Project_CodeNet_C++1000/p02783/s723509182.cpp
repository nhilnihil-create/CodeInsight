

#include<stdio.h>


int main(){
     
    int H;
    int A;
    
    
    
    scanf("%d %d", &H, &A);
    int Damage = H%A;
    Damage == 0 ? printf("%d", H/A ):printf("%d", H/A+1);
    
    
    
    
     
     
     
     
    
    return 0;
}