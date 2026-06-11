#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define rep(i,l,r) for(rint i=l;i<=r;i++)
#define per(i,l,r) for(rint i=l;i>=r;i--)
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back 
#define fir first
#define sec second
template<typename T1,typename T2>void ckmin(T1 &a,T2 b){if(a>b)a=b;}
template<typename T1,typename T2>void ckmax(T1 &a,T2 b){if(a<b)a=b;}
template<typename T>T gcd(T a,T b){return b?gcd(b,a%b):a;}
int read(){
  int x=0,f=0;
  char ch=getchar();
  while(!isdigit(ch))f|=ch=='-',ch=getchar();
  while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
  return f?-x:x;
}
const int N=200005;
int pre[N][2],suf[N][2];
char s[N];
int n;
int main(){
  scanf("%d%s",&n,s+1);
  for(int i=1;i<=n;i++){
    pre[i][0]=pre[i-1][0];
    pre[i][1]=pre[i-1][1];
    int typ=s[i]=='R';
    pre[i][typ]++;
  }
  for(int i=n;i>=1;i--){
    suf[i][0]=suf[i+1][0];
    suf[i][1]=suf[i+1][1];
    int typ=s[i]=='R';
    suf[i][typ]++;
  }
  int ans=1e9;
  for(int i=0;i<=n;i++){
    int x=pre[i][0];
    int y=suf[i+1][1];
    ans=min(ans,x+y-min(x,y));
  }
  printf("%d\n",ans);
  return 0;
}