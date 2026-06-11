#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

ll N,a,total,ans,t;
ll cumu[200001];
int main(){
  cin>>N;
  cumu[0]=0; REP(i,N){ cin>>a; cumu[i+1]=cumu[i]+a;}
  total = cumu[N];
  ans = total;
  for(int i=1;i<N;++i){
    t = total-cumu[i]*2;
    if(abs(t)<ans){ans=abs(t);}
    if(t<=0){break;}
  }
  cout << ans<<"\n";
}