#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec[i];
  }
  
  
  int x=0;
  
  for(int i=0;i<N;i++){
    if(vec[i]!=i+1){
      x++;
    }
  }
  
  if(x<=2){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}