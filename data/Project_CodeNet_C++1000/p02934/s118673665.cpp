#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<double> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  double sum=0;
  for(int i=0;i<N;i++){
    double x=1/vec.at(i);
    sum+=x;
  }
  cout<<1/sum<<endl;
}
    