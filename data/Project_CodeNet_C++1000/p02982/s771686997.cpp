#include<bits/stdc++.h>
using namespace std;

int main() {
  int N,D;cin>>N>>D;
  vector<vector<int>> X(N,vector<int>(D));
  for(int i=0;i<N;i++){
    for(int j=0;j<D;j++) cin>>X.at(i).at(j);
  }
  int Nt=N*(N-1)/2;
  vector<int> A(Nt);
  int dist=0;
  int F=0;
  for(int i=0;i<N-1;i++){
    for(int k=i+1;k<N;k++){
      for(int j=0;j<D;j++) dist +=(X.at(i).at(j)-X.at(k).at(j))*(X.at(i).at(j)-X.at(k).at(j));
      A.at(F)=dist;
      dist=0;
      F++;
    }
  }
  int count=0;
  for(int h=1;h<130;h++){
    for(int i=0;i<Nt;i++){
      if(A.at(i)==h*h) count++;
    }
  }
  cout<<count<<endl;
}