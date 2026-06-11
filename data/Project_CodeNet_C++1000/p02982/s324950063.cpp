#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,D;
  cin>>N>>D;
  
  vector<vector<int>> vec(N, vector<int>(D));
  for(int i=0;i<N;i++){
    for(int j=0;j<D;j++){
      cin>>vec.at(i).at(j);
    }
  }
  int kai=0;
  for(int i=0;i<N;i++){
    for(int j=i;j<N;j++){
      int64_t sum=0;
      for(int k=0;k<D;k++){
        sum+=(vec.at(i).at(k)-vec.at(j).at(k))
          *(vec.at(i).at(k)-vec.at(j).at(k));
      }
      for(int m=1;m<=1000;m++){
        if(m*m==sum){
          kai++;
          break;
        }
      }
    }
  }
  cout<<kai<<endl;      
        

}