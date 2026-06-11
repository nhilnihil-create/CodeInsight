#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> x(N);
  for(int i=0; i<N; i++){
    cin>>x.at(i);
  }
  sort(x.begin(),x.end());
  int ans=100000000;
  int y;
  for(int i=1; i<101; i++){
    int sum=0;
    for(int j=0; j<N; j++){
      y=x.at(j)-i;
      sum=sum+y*y;
    }
    if(sum<ans) ans=sum;
  }
  cout<<ans<<endl;
}