#include <bits/stdc++.h>
using namespace std;

# define Rep(i,a,b) for(int i=a;i<=b;i++)
# define _Rep(i,a,b) for(int i=a;i>=b;i--)
# define RepG(i,u) for(int i=head[u];~i;i=e[i].next)

typedef long long ll;

const int N=3005;
const int mod=998244353;

template<typename T> void read(T &x){
   x=0;int f=1;
   char c=getchar();
   for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
   for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
    x*=f;
}

int n,m;
int a[N];
int f[N][N];
int mi[N];

int main()
{
    read(n),read(m);
    Rep(i,1,n)read(a[i]);
    f[0][0]=1;
    Rep(i,1,n){
        Rep(j,0,m){
            f[i][j]=f[i-1][j]*2%mod;
            if(j>=a[i])f[i][j]+=f[i-1][j-a[i]],f[i][j]%=mod;
        }
    }
    printf("%d\n",f[n][m]);
    return 0;
}