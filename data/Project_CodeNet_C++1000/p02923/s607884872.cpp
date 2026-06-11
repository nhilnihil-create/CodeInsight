#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin>>N;
  
  vector<int64_t> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  int sai=0;
  int sum=0;
  for(int i=1;i<N;i++){ 
    if(vec.at(i-1)>=vec.at(i)) sum++;
    else{
    sai=max(sai,sum);
    sum=0;
    }
  }
  cout<<max(sai,sum)<<endl; 
  
}