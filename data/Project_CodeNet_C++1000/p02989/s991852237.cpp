#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){

  int N;
  cin>>N;
  vector<int> D(N);
  for(int i=0;i<=N-1;i++){
  
    cin>>D[i];
  }
  sort(D.begin(),D.end());
  cout<<D[N/2]-D[N/2-1];
  return 0;
}