#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+100;
#define fr(i,a,b) for(int i = a;i <= b; ++i)
#define nfr(i,a,b) for(int i = a;i >= b; --i)

int n,m;

inline int lucas(int x,int y){
   if(y < 2){
      if(y == 0)return 1;
      else return x%2;
   }
   return 1LL*lucas(x/2,y/2)*lucas(x%2,y%2)%2;
}

int a[N],b[N];
int main(){
   scanf("%d\n",&n);
   fr(i,1,n){
      char ch; ch = getchar();
      a[i] = ch-'0';
   }
   fr(i,1,n-1)b[i] = a[i+1] >= a[i] ? a[i+1]-a[i] : a[i]-a[i+1];
   --n;

   int res1 = 0;
   fr(i,1,n){
      res1 ^= lucas(n-1,i-1)*(b[i]%2);
   }
   if(res1 == 1)puts("1");
   else {
      fr(i,1,n){
         if(b[i] == 1){
            puts("0"); return 0;
         }
      }
      int res2 = 0;
      fr(i,1,n){
         res2 ^= lucas(n-1,i-1)*((b[i]/2)%2);
      }
      if(res2){
         puts("2");
      } else puts("0");
   }
   return 0;
}
