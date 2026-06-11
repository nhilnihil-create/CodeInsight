#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
  cin>>N;
 vector<int>line(N,0);
  for(int i=0;i<N;i++){
  cin>>line.at(i);
  }
  int ans=1000101010;
  for(int i=1;i<=100;i++){
    int sum=0;
  	for(int j=0;j<N;j++){
    sum+=(line.at(j)-i)*(line.at(j)-i);
    }
    ans=min(ans,sum);
   }
  cout<<ans<<endl;
}