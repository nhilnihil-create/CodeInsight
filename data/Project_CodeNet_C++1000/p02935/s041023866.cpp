#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> v(N);
  for(int i=0;i<N;i++){
    cin>>v.at(i);
  }
  sort(v.begin(),v.end());
  double x=(v.at(0)+v.at(1))/2.0;
  for(int i=2;i<N;i++){

    x=(x+v.at(i))/2.0;
  }
  cout<<x<<endl;
}
