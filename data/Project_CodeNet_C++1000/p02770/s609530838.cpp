#include <bits/stdc++.h>
#define ll long long
#define MAX 5005
using namespace std;

template<typename T>
void read(T &n){
    n = 0;
    T f = 1;
    char c = getchar();
    while(!isdigit(c) && c != '-') c = getchar();
    if(c == '-') f = -1, c = getchar();
    while(isdigit(c)) n = n*10+c-'0', c = getchar();
    n *= f;
}
template<typename T>
void write(T n){
    if(n < 0) putchar('-'), n = -n;
    if(n > 9) write(n/10);
    putchar(n%10+'0');
}

int n, q;
ll m, x, P, d[MAX];

int main()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        read(d[i]);
    }
    while(q--){
        read(m), read(x), read(P);
        ll s1 = 0, s2 = x;
        for(int i = 1; i <= n; i++){
            if(d[i]%P == 0) s1 += ((m-1)/n+(i-1<(m-1)%n));
            else s2 += ((m-1)/n+(i-1<(m-1)%n))*(d[i]%P);
        }
        s2 = s2/P-x/P;
        write(m-1-s1-s2), puts("");
    }

    return 0;
}