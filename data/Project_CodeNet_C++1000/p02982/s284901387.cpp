#include<bits/stdc++.h>
using namespace std;

int main() {
  int N,D,count=0;
  cin >> N >> D;
  vector<vector<int>> X(N,vector<int>(D));
  for(int i=0;i<N;i++){
    for(int j=0;j<D;j++){
      cin >> X.at(i).at(j);
    }
  }
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
      int dis=0;
      for(int k=0;k<D;k++){
        int A=X.at(i).at(k)-X.at(j).at(k);
        dis+=A*A;
      }
      for(int k=1;k<128;k++){
        if(dis==k*k){
          count++;
          break;
        }
      }
    }
  }
  cout << count << endl;
}