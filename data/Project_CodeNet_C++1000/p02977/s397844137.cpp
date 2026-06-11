#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
using namespace std;
#define PII pair<int,int>
const int maxn=100500;
int n;
int main(){
    scanf("%d",&n);
    int t=1;
    while (t<n) t*=2;
    if (n==t) puts("No");
    else {
        puts("Yes");
        if (n&1) {
            for (int i=2;i<=n;i+=2){
                printf("%d %d\n",1,i);
                printf("%d %d\n",i,i+1);
                printf("%d %d\n",1,i+n+1);
                printf("%d %d\n",i+1+n,i+n);
            }
            printf("%d %d\n",1+n,n+2);
        }
        else {
            for (int i=2;i<=n-1;i+=2){
                printf("%d %d\n",1,i);
                printf("%d %d\n",i,i+1);
                printf("%d %d\n",1,i+n+1);
                printf("%d %d\n",i+1+n,i+n);
            }
            printf("%d %d\n",1+n,n+2);
            rep(i,2,n-1) if ((1^i^n)<n){
                int x=i^1^n;
                printf("%d %d\n",i,n);
                if (x&1) printf("%d %d\n",n+x,2*n);
                else printf("%d %d\n",x,2*n);
                break;
            }
        }
    }
    return 0;
}