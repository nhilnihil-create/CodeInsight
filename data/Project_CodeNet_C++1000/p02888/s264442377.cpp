#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<int>L(N);
  for(int i=0;i<N;i++){
    cin>>L[i];
  }
  sort(L.begin(),L.end());
  int sum=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      int x=L[i]+L[j];
      int r=lower_bound(L.begin(),L.end(),x)-L.begin();
      sum+=(r-1-j);
    }
  }
  cout<<sum<<endl;
  return 0;
}