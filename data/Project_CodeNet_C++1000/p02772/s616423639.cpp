#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {

  int N;cin>>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  
  int even=0;
  for(int i=0;i<N;i++){
    if(vec.at(i)%2==0){
      even++;
    }
  }
  
  int check=0;
  for(int i=0;i<N;i++){
    if(vec.at(i)%6==0||vec.at(i)%10==0){
      check++;
    }
  }
  
  if(even==check){
    cout<<"APPROVED"<<endl;
  }
  else{
    cout<<"DENIED"<<endl;
  }
}
  

  
