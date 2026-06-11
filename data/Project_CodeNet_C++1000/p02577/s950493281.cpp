#include <stdio.h>
#include <string.h>

int main(void){
    int sum = 0,len;
    char num[200010]; 
    scanf("%s",num);

   len =  strlen(num);
  

    for(int i = 0;i < len; i++)
    {
        sum += num[i] - '0';
    }

   
    if(sum % 9 == 0)
    {
        printf("Yes\n");
    }else
    {
        printf("No\n");
    }
    
    return 0;
    
}


