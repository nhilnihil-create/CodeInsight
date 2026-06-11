#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    char s[10];
    scanf("%d%s", &a, s);
    int n = strlen(s);
    if(a < 3200)
        puts("red");
    else
        printf("%s", s);
    return 0;
}
