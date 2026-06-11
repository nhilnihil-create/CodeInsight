#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
using namespace std;
typedef long long i64;
inline int read(int f = 1, int x = 0, char ch = ' ')
{
    while(!isdigit(ch = getchar())) if(ch == '-') f = -1;
    while(isdigit(ch)) x = x*10+ch-'0', ch = getchar();
    return f*x;
}
const int N = 1e3+5;
int k, n, a[N][N];
int main()
{
    n = read(); if((n&-n) == n) return puts("No"), 0;
    puts("Yes");
    printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n", n+1, n+1, n+2, n+2, n+3);
    for(int i = 2; i*2+1 <= n; ++i) 
        printf("1 %d\n1 %d\n%d %d\n%d %d\n", 2*i, 2*i+1, 2*i, n+2*i+1, 2*i+1, n+2*i);
    if(~n&1)
        for(int x = 2; x <= n; ++x)
        {
            int y = n^x^1; if(x == 3||y == 3||y > n) continue;
            printf("%d %d\n%d %d\n", n, x, n*2, y); break;
        }
    return 0;
}