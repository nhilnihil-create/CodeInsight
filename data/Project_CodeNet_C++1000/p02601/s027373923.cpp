#include<cstdio>
#include<algorithm>
#include<cmath>
typedef long long ll;
int a,b,c,k,num = 0;

template<typename T>
inline void read(T &x){
    x = 0; char ch = getchar(); int f = 1;
    for(;ch < '0' || ch > '9'; ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
    x *= f;
}

int main(){
    read(a); read(b); read(c); read(k);
    while(b <= a) b <<= 1, num++;
    while(c <= b) c <<= 1, num++;
    if(num <= k) printf("Yes\n");
    else printf("No\n");
    return 0;
}
/*
3
1
-1
-1

2
*/