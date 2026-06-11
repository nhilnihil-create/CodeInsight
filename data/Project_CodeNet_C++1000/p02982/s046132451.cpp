#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
  int N,D;
  cin >> N >> D;
  vector<vector<int>> x(N,vector<int>(D));
  for(int i = 0; i<N; i++){
    for(int j= 0; j<D; j++){
    cin >> x.at(i).at(j);
  }
  }
  int count = 0;
  for(int i = 0; i<N-1; i++){
    for(int k = i+1; k<N; k++){
      int sum = 0;
    for(int j= 0; j<D; j++){
      sum += (x.at(i).at(j) - x.at(k).at(j))*(x.at(i).at(j) - x.at(k).at(j));
    }
  
    double ans = sqrt(sum);
   // cout << ans << endl;
    if(ans == floor(ans)){
      count ++;
    }
  }
  }
  cout << count << endl;
}