#include <stdio.h>
#include <string.h>

int main (){
    long long int n;
    scanf("%lld", &n);
    int count = 0;
    char name[255] = {0};
    n--;
    while (n >= 0){
        name[count] = (n % 26) + 'a';
        n /= 26;
        count++;
        n--;
    }
    int len=strlen(name);
    for(int i = len-1; i >= 0; i--){
        printf("%c", name[i]);
    }
    puts("");

    return 0;
}