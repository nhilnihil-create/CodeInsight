#include <cstdio>
#include <ctype.h>
using namespace std;

int main(){
    char str[1200];
    gets(str);
    int i = 0;
    while(str[i] != '\0'){
        char uc, lc;
        uc = toupper(str[i]);
        lc = tolower(str[i]);

        if(lc == str[i]) printf("%c", uc);
        else printf("%c", lc);
        ++i;
    }
    printf("\n");
    return 0;
}