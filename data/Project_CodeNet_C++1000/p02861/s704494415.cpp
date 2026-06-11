#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<vector<int>> A(N,vector<int>(2));
  for(vector<int> &i:A){
    cin>>i.at(0)>>i.at(1);
  }
  double k=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      int x=A.at(i).at(0)-A.at(j).at(0),y=A.at(i).at(1)-A.at(j).at(1);
      k+=pow(x*x+y*y,0.5);
    }
  }
  cout<<setprecision(16)<<k*2/N<<endl;
}
