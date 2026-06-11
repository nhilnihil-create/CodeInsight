#include <bits/stdc++.h>
using namespace std;

# define Rep(i,a,b) for(int i=a;i<=b;i++)
# define _Rep(i,a,b) for(int i=a;i>=b;i--)
# define RepG(i,u) for(int i=head[u];~i;i=e[i].next)

typedef long long ll;

const int N=2e5+5;

template<typename T> void read(T &x){
   x=0;int f=1;
   char c=getchar();
   for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
   for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0';
    x*=f;
}

int n;
int l[N],r[N];
int p,q;

int main()
{
    read(n);
    Rep(i,1,n)read(l[i]),read(r[i]);
    sort(l+1,l+n+1);
    sort(r+1,r+n+1);
    if(n%2==0){
        p=l[n>>1]+l[(n>>1)+1],q=r[n>>1]+r[(n>>1)+1];
        printf("%d\n",q-p+1);
    }
    else{
        p=l[n+1>>1],q=r[n+1>>1];
        printf("%d\n",q-p+1);
    }
    return 0;
}