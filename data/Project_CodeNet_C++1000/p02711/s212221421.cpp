#include <stdio.h>

int main(){
    char arr[4];
    scanf ("%[^\n]", arr);
    for (int i = 0; arr[i] != '\0'; i++)
        if (arr[i] == '7') return puts ("Yes"), 0;
    puts ("No");
}
