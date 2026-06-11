#include <bits/stdc++.h>
 
int main() {
    unsigned long long a, b;
    char s[6];
 
    scanf("%lld%s", &a, s);
    b = (s[0]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0'); 
 
    printf("%llu\n", a*b/100);
 
    return 0;
}