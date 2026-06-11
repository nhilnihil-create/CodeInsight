#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

const int CN = 1e6 + 6;

int read(){
    int s = 0,ne = 1; char c = getchar();
    while(c < '0' || c > '9') ne = c == '-' ? -1 : 1, c = getchar();
    while(c >= '0' && c <= '9') s = (s << 1) + (s << 3) + c - '0', c = getchar();
    return s * ne;
}

int p[CN], mp[CN]; bool np[CN];
void sieve(int n){
    np[1] = true;
    for(int i = 2; i <= n; i++){
        if(!np[i]) p[ ++p[0] ] = i, mp[i] = i;
        for(int j = 1; j <= p[0] && i * p[j] <= n; j++){
            int x = i * p[j]; np[x] = true, mp[x] = p[j];
            if(!(i % p[j])) break;
        }
    }
}

int n, a[CN]; bool vis[CN];

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}
int Gcd(int *a){
    int g = a[1]; for(int i = 2; i <= n; i++) g = gcd(g, a[i]);
    return g;
}

int main()
{
    // freopen("_in.in", "r", stdin);
    sieve(1e6);
    n = read(); for(int i = 1; i <= n; i++) a[i] = read();
    
    bool flag = true;
    for(int i = 1; i <= n && flag; i++){
        int cur = a[i];
        while(cur ^ 1){
            int u = mp[cur];
            if(vis[u]) flag = false;
            vis[u] = true;
            while(!(cur % u)) cur /= u;
        }
    }

    if(flag) puts("pairwise coprime");
    else puts(Gcd(a) == 1 ? "setwise coprime" : "not coprime");
}