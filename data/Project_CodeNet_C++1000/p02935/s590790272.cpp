#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin>>N;
  
  vector<double> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  
  sort(vec.begin(),vec.end());
  for(int i=0;i<N-1;i++){
    vec.at(i+1)=(vec.at(i)+vec.at(i+1))/2;
  }
  cout << fixed << setprecision(7) <<vec.at(N-1)<< endl;
  
 
  
}
