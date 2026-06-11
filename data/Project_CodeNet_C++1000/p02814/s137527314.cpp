#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;i++)
using namespace std;

int main(){
  int N,M,a,L;
  vector<int> v;
  scanf("%d%d%d",&N,&M,&a);
  L=a/=2;
  v.push_back(a);
  REP(i,N-1){
    scanf("%d",&a);
    a/=2;
    L=lcm(L,a);
    v.push_back(a);
  }
  REP(i,N){
    if((L/v[i])%2==0){
      cout<<0<<endl;
      return 0;
    }
  }
  cout<<M/L-M/(L*2)<<endl;
}