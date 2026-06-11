#include<stdio.h>
#include<string.h>

int main()
{
    char str[20];
    scanf(" %s",str);
    fflush(stdin);
    if(strcmp(str,"Sunny")==0){
        printf("Cloudy");
    }
    else if(strcmp(str,"Cloudy")==0){
        printf("Rainy");
    }
    else if(strcmp(str,"Rainy")==0){
        printf("Sunny");
    }
}
