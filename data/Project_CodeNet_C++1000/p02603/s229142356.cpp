#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define int long long
int read(){
    int s = 0,ne = 1; char c = getchar();
    while(c < '0' || c > '9') ne = c == '-' ? -1 : 1, c = getchar();
    while(c >= '0' && c <= '9') s = (s << 1) + (s << 3) + c - '0', c = getchar();
    return s * ne;
}
int n, a[81], f[81];
signed main()
{
    // freopen("_in.in", "r", stdin);
    n = read(); for(int i = 1; i <= n; i++) a[i] = read();
    f[1] = 1000;
    for(int i = 2; i <= n; i++){
        f[i] = f[i - 1];
        for(int j = 1; j < i; j++) f[i] = max(f[i], f[j] + (f[j] / a[j]) * (a[i] - a[j]));
    }    
    printf("%lld", f[n]);
}