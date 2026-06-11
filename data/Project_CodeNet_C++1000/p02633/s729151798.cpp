#include<bits/stdc++.h>
using namespace std;
int calc(int x){
    if(!(360 % x)) return 360 / x;
    return calc(360 % x) * (360 / x);
}
inline int read(void){
    int num = 0, f = 1;
    char ch;
    while(!isdigit(ch=getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) num = num*10 + ch-'0', ch = getchar();
    return num * f; 
}
int main()
{
    int x = read();
    printf("%d\n", calc(x));
    return 0;
}
