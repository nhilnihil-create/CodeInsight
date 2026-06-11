#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
const int P = 1e9+7;
#define fr(i,low,up,st) for(register int i = low;i <= up;i += st)
#define nfr(i,low,up,st) for(register int i = low;i >= up;i -= st)
#define clr(a) memset(a,0,sizeof a)
#define SZ(a) (a.size())

int n,m,k;
char ch[N];
int a[N];
int cnt;
int ans = 1;
int bc = 0,wc = 0;
int main(){
   scanf("%d",&n);
   scanf("%s",ch+1);
   fr(i,1,2*n,1){
      if(i%2 == 1 && ch[i] == 'B')a[i] = 1,++bc;
      else if(i%2 == 0 && ch[i] == 'W')a[i] = 1,++wc;
      else if(i%2 == 0 && ch[i] == 'B')a[i] = -1,--bc;
      else a[i] = -1,--wc;
      if(bc < 0 || wc < 0){
         puts("0");
         return 0;
      }
   }
   if(bc || wc){
      puts("0");
      return 0;
   }
   fr(i,1,2*n,1){
      cnt += a[i];
      if(cnt < 0){
         puts("0"); return 0;
      }
      if(a[i] == -1)ans = 1LL*ans*(cnt+1)%P;
   }
   if(cnt != 0)puts("0");
   fr(i,1,n,1){
      ans = 1LL*ans*i%P;
   }
   printf("%d\n",ans);
   return 0;
}
