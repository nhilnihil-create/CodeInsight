#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,X;
  cin>>N>>X;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
    int a=0;
    for(int i=0;i<N;i++){
      a+=vec.at(i);
    }
  if(a<=X) cout<<N+1<<endl;
  else{
  int z=0;
  int count=0;
  for(int i=0;i<N;i++){
    z+=vec.at(i);
    count++;
    if(z>X) break;
  }
  cout<<count<<endl;
  }
}