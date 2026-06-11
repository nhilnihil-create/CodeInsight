#include <bits/stdc++.h>

char s[4];

int main(){
    scanf("%s", s);
    if (s[1] == 'R'){
        printf("%d\n", 1 + (s[0] == 'R') + (s[2] == 'R'));
    }
    else{
        printf("%d\n", int(s[0] == 'R' || s[2] == 'R'));
    }
    return 0;
}