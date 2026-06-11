#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin>>n;
    if ((1<<(int)log2(n))==n) return puts("No"),0;
    puts("Yes"),printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
    for (int i=4;i<n;i+=2) printf("%d %d\n%d %d\n%d %d\n%d %d\n",i,1,i+1,1,i,i+n+1,i+1,i+n);
    if (!(n&1)) for (int i=2;i<=n;i++) {
        int w=i^1^n; if (i==3 || w==3 || w>n) continue;
        printf("%d %d\n%d %d\n",n,i,n+n,w); break;
    }
    return 0;
}