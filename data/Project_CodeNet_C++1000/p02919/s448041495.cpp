#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int man = 2e5+10;
#define IOS ios::sync_with_stdio(0)
template <typename T>
inline T read(){T sum=0,fl=1;int ch=getchar();
for(;!isdigit(ch);ch=getchar())if(ch=='-')fl=-1;
for(;isdigit(ch);ch=getchar())sum=sum*10+ch-'0';
return sum*fl;}
template <typename T>
inline void write(T x) {static int sta[35];int top=0;
do{sta[top++]= x % 10, x /= 10;}while(x);
while (top) putchar(sta[--top] + 48);}
template<typename T>T gcd(T a, T b) {return b==0?a:gcd(b, a%b);}
template<typename T>T exgcd(T a,T b,T &g,T &x,T &y){if(!b){g = a,x = 1,y = 0;}else {exgcd(b,a%b,g,y,x);y -= x*(a/b);}}
#ifndef ONLINE_JUDGE
#define debug(fmt, ...) {printf("debug ");printf(fmt,##__VA_ARGS__);puts("");}
#else
#define debug(fmt, ...)
#endif
typedef long long ll;
const ll mod = 1e9+7;
int x[man];
int l[man],r[man];
int pos[man];
int main() {
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt","w",stdout);
    #endif
    int n = read<int>();
    for(int i = 1;i<= n;i++){
        x[i] = read<int>();
        pos[x[i]] = i;
        l[i] = i-1;
        r[i] = i+1;
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++){
        int lpos1 = l[pos[i]];
        int lpos2 = l[lpos1];
        int rpos1 = r[pos[i]];
        int rpos2 = r[rpos1];
        if(lpos1)ans += 1ll*(lpos1 - lpos2)*(rpos1 - pos[i])*i;
        if(rpos1!=n+1)ans += 1ll*(rpos2 - rpos1)*(pos[i] - lpos1)*i;
        l[rpos1] = lpos1;
        r[lpos1] = rpos1;
    }
    write(ans);
    return 0;
}