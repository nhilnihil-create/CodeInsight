#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector <int> vec(N, 0);
  for(int i=0; i<N; i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(), vec.end());
  double ans=0;
  ans=vec.at(0)*pow(2, 1-N);
  for(int i=1; i<N; i++){
    ans+=vec.at(i)*pow(2,i-N);
  }
  cout<<ans<<endl;
}