#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
const int INF=1001001001;

int main() {
  int N;
  cin>>N;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.rbegin(),A.rend());
  int64_t sum=0;
  int cnt=N-1;
  for(int i=0;i<N;i++){
    if(i==0){sum+=A[i];cnt--;}
    else{
      for(int j=0;j<2;j++){
        if(cnt>0){
          sum+=A[i];
          cnt--;
        }
      }
    }
  }
  cout<<sum<<endl;
  return 0;
}