// ===================================
//   author: M_sea
//   website: http://m-sea-blog.com/
// ===================================
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

int main() {
    int n=read();
    if (__builtin_popcount(n)==1) { puts("No"); return 0; }
    puts("Yes");
    printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",1+n,1+n,2+n,2+n,3+n);
    for (int i=4;i+1<=n;i+=2)
        printf("1 %d\n1 %d\n%d %d\n%d %d\n",i,i+1,i,i+1+n,i+1,i+n);
    if ((n&1)==0) {
        for (int i=2;i<n;++i) {
            if (i==3) continue;
            int j=n^i^1;
            if (j!=3&&j<n) { printf("%d %d\n%d %d\n",i,n,j,n+n); break; }
        }
    }
    return 0;
}