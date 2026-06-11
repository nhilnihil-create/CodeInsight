#include <bits/stdc++.h>
#define int long long
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
//typedef long long int int;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int INF=100100100100100;
int a[100010],b[100010];

signed main(){
  int A,B,m;cin>>A>>B>>m;
  int ans=INF;
  REP(i,A)cin>>a[i];
  REP(i,B)cin>>b[i];
  REP(i,m){
    int x,y,c;cin>>x>>y>>c;x--;y--;
    ans=min(ans,a[x]+b[y]-c);
  }
  sort(a,a+A);
  sort(b,b+B);
  ans=min(ans,a[0]+b[0]);
  cout<<ans<<endl;
  
    
  return 0;
}