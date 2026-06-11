#include <stdio.h>


int main(){
    char s[1300];
    int cnt[26]={0};
    
    while (gets(s)!=NULL){
        for (char *p=s; *p!='\0'; p++){
            if (*p >='a' && *p <= 'z'){
                cnt[*p - 'a']++;
            } else if (*p >='A' && *p <= 'Z'){
                cnt[*p - 'A']++;
            }
        }
    }
    
    for (int i=0; i<26; i++){
        printf("%c : %d\n",'a'+i, cnt[i]);
    }
    

    return 0;
}