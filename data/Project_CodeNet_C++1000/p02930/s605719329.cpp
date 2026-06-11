#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+10;
const int P = 1e9+7;
#define fr(i,low,up,st) for(register int i = low;i <= up;i += st)
#define nfr(i,low,up,st) for(register int i = low;i >= up;i -= st)
#define clr(a) memset(a,0,sizeof a)
#define SZ(a) (a.size())

int ga[N][N];

void solve(int l,int r,int ct){
   if(l == r)return ;
   int mid = (l+r)/2;
   fr(i,l,mid,1){
      fr(j,mid+1,r,1){
         ga[i][j] = ct;
      }
   }
   solve(l,mid,ct+1);
   solve(mid+1,r,ct+1);
}

int main(){
   int n;
   scanf("%d",&n);
   solve(1,n,1);
   fr(i,1,n,1){
      fr(j,i+1,n,1){
         printf("%d ",ga[i][j]);
      }
      puts("");
   }
}
