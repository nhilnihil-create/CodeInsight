#include <bits/stdc++.h>
using namespace std;



int main(){
  int N;
  cin>>N;
  vector<string> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  int sum=0;
  for(int i=1;i<N;i++){
    if(vec.at(i-1)==vec.at(i)) sum+=1;
  }
  cout<<N-sum<<endl;
}