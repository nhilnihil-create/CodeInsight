#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
const int N=100005;

int lowbit(int x){return x&-x;}
int main(){
  //  freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int n;cin>>n;
    if (lowbit(n)==n) {puts("No");return 0;}
    puts("Yes");
    int m=n-(n+1)%4,s=m+1;
    printf("2 1\n%d %d\n",2+n,1+n);
    printf("1 3\n%d %d\n",1+n,3+n);

    if (n==m+1){
        int t=m^(m+1);
        for (int i=3;i<m;i++){
            if (i==t) continue;
            int x= i+1==t ? i+2 : i+1 ;
            printf("%d %d\n%d %d\n",i,x,i+n,x+n);
        }
        printf("%d %d\n%d %d\n",m,t,m+n,t+n);
        printf("%d %d\n",t,2+n);
        printf("%d %d\n%d %d\n",n,m,n+n,t);
        return 0;
    }

    for (int i=3;i<m;i++) printf("%d %d\n%d %d\n",i,i+1,i+n,i+n+1);
    printf("%d %d\n",m,2+n);
    if (n==m+2){
        printf("%d %d\n%d %d\n",s,s+1,s+n,s+1+n);
        printf("%d 1\n%d 1\n",s+1,s+n);
    } else if (n==m+3){
        printf("%d %d\n%d %d\n",s,s+1,s+n,s+1+n);
        printf("%d 1\n%d 1\n",s,s+1+n);
        printf("%d %d\n%d 3\n",s,s+2,s+2+n);
    }

    return 0;
}
