#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (1LL<<60)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef unsigned long long int ull;
typedef long long lint;

int main(void){
  int N;
  cin >> N;
  int A[N];
  pint res[N-1];
  rep(i,N) cin >> A[i];
  sort(A,A+N);
  int ans=A[N-1];
  int mini=A[0],maxi=A[N-1];
  if(maxi<0){
    rep(i,N-1){
      res[i].first=ans,res[i].second=A[i];
      ans-=A[i];
    }
  }
  else if(mini>0){
    rep(i,N-2){
      res[i].first=A[0],res[i].second=A[i+1];
      A[0]-=A[i+1];
    }
    res[N-2].first=A[N-1],res[N-2].second=A[0];
    ans-=A[0];
  }
  else{
    int np=1,pp=N-2,count=0;
    while(A[np]<=0 && count<N-1){
      res[count].first=ans,res[count].second=A[np];
      ans-=A[np];
      np++;
      count++;
    }
    while(A[pp]>0 && count<N-1){
      res[count].first=A[0],res[count].second=A[pp];
      A[0]-=A[pp];
      pp--;
      count++;
    }
    res[N-2].first=ans,res[N-2].second=A[0];
    ans-=A[0];
  }
  cout << ans << endl;
  rep(i,N-1) cout << res[i].first << " " << res[i].second << endl;
}