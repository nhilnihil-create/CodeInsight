#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int64_t N,M,V,P;
vector<int64_t>A;

bool f(int i){//iは0インデックス
  if(i<=P-1){return true;}
  int64_t imx=A[i]+M;
  if(imx<A[P-1]){return false;}
  int64_t sum=0;
  sum+=(P-1)*M;
  sum+=(N-i)*M;//iは0インデックス
  for(int j=P-1;j<i;j++){
    sum+=max((int64_t)0,imx-A[j]);
  }
  return sum>=M*V;
}
int main(){
  cin>>N>>M>>V>>P;
  A.resize(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.rbegin(),A.rend());
  
  int l=-1,r=N;
  while(r-l>1){
    int mid=(r+l)/2;
    if(f(mid)){l=mid;}
    else{r=mid;}
  }
  cout<<l+1<<endl;//l,rは0インデックス
  return 0;
}