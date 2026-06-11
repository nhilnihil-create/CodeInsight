#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
const int N=100005;
int vis[N];
vector<int> vp;
int lowbit(int x){return x&-x;}
int main(){
  //  freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int n;cin>>n;
    if (lowbit(n)==n) {puts("No");return 0;}
    puts("Yes");
    int m=n-(n+1)%4,s=m+1;
    if (m==n||n==m+2||lowbit(n-2)==n-2){
        printf("2 1\n%d %d\n",2+n,1+n);
        printf("1 3\n%d %d\n",1+n,3+n);
        for (int i=3;i<m;i++) printf("%d %d\n%d %d\n",i,i+1,i+n,i+n+1);
        printf("%d %d\n",m,2+n);

        if (n==m+2){
            printf("%d %d\n%d %d\n",s,s+1,s+n,s+1+n);
            printf("%d 1\n%d 1\n",s+1,s+n);
        } else if (n>=5&&lowbit(n-2)==n-2){
            printf("%d %d\n%d %d\n",s,s+1,s+n,s+1+n);
            printf("%d 1\n%d 1\n",s,s+1+n);
            printf("%d %d\n%d 3\n",s,s+2,s+2+n);
        }
        return 0;
    }

    while (s) {int x=lowbit(s);vis[x]=1;vp.pb(x);s-=x;}
    vp.pb(1),vp.pb(3);vis[1]=vis[3]=1;
    for (int i=1;i<vp.size();i++){
        int x=vp[i],y=vp[i-1];
        printf("%d %d\n%d %d\n",x,y,x+n,y+n);
    }

    for (int i=m+1;i<=n;i++){
        printf("%d %d\n",i,vp[0]);
        if (i==m+1) printf("%d %d\n",i+n,vp[vp.size()-3]);
        if (i==m+2) printf("%d 1\n",i+n);
        if (i==m+3) printf("%d 3\n",i+n);
    }

    int last=3;
    for (int i=1;i<=m;i++) if (!vis[i]){
        printf("%d %d\n%d %d\n",i,last,i+n,last+n);
        last=i;
    }
    printf("%d %d\n",last,vp[0]+n);

    return 0;
}
