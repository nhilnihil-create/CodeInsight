#include<iostream>
#include<cmath>
#include<complex>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define NEXT(i,n) ((i+1)%(n))
const int N = 1000001;
int dp1[N],dp2[N];  
main(){
  vector<int> simen;
  REP(i,1,N+1){
    simen.push_back(i*(i+1)*(i+2)/6);
    if (simen[i-1] > N+1)break;
  }
  
  dp1[0]=0;
  dp2[0]=0;
  REP(i,1,N){
    dp1[i]=10000000;
    dp2[i]=10000000;
    rep(j,simen.size()){
      if (i-simen[j] < 0)break;
      dp1[i]=min(dp1[i],dp1[i-simen[j]]+1);
      if (simen[j]%2 == 1){
	dp2[i]=min(dp2[i],dp2[i-simen[j]]+1);
      }
    }
  }
  
  int n;
  while(cin>>n && n){
    cout << dp1[n] <<" " << dp2[n] << endl;
  }

}