#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 201;
#define fr(i,a,b) for(int i = a;i <= b; ++i)
#define nfr(i,a,b) for(int i = a;i >= b; --i)

struct LB{
   ll x[65];
   void init(){
      memset(x,0,sizeof x);
   }
   void insert(ll v){
      nfr(i,63,0){
         if((v >> i)&1){
            if(!x[i]){
               x[i] = v; return ;
            } else v ^= x[i];
         }
      }
   }
   bool query(ll v){
      nfr(i,63,0){
         if((v >> i)&1){
            if(x[i])v ^= x[i];
            else return false;
         }
      }
      return true;
   }
}l;

int n,m;
ll a[N];
char s[N];
void solve(){
   scanf("%d",&n);
   fr(i,1,n)scanf("%lld",a+i);
   scanf("%s",s+1);
   l.init();

   bool flag = true;
   nfr(i,n,1){
      if(s[i] == '0')l.insert(a[i]);
      else flag &= l.query(a[i]);
   }
   printf("%d\n",flag^1);
}

int t;
int main(){
   scanf("%d",&t);
   while(t--)solve();
   return 0;
}
