#include<iostream>
#include<cctype>
#include<cstdio>
using namespace std;

int main(){
    int i = 0;
    char ch[1200];
    while(++i < 1200){

        scanf("%c", &ch[i]);
        if(ch[i] == '\n'){
            printf("%c", ch[i]);
            break;
        } else if(isalpha(ch[i])){
            if (islower(ch[i])){
                ch[i] = toupper(ch[i]);
            
            }else if(isupper(ch[i])){
                ch[i] = tolower(ch[i]);
            }
        }
         printf("%c", ch[i]);
         
    
    }
 
    return 0;
}
