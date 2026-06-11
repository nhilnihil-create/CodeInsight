#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,M;
  int big=1000000007;
  cin >> N >> M;
  vector<int>data(N);
  for(int i=0;i<N;i++){
    cin >> data.at(i);
  }
  int64_t res=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(data.at(i)>data.at(j)) res++;
    }
  }
  vector<int>ans(2000);
  for(int i=0;i<N;i++){
    ans.at(data.at(i)-1)++;
  }
  int64_t ress=0;
  int a=0;
  for(int i=0;i<2000;i++){
    ress+=a*ans.at(i);
    a+=ans.at(i);
    ress%=big;
  }
  
  int64_t b=(M*(M-1)/2)%big;
  int64_t aans=((res*M)%big+(ress*b)%big)%big;
  cout << aans;
}