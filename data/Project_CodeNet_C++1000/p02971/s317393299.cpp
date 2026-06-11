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
  
  vector<int> X(N);
  for(int i=0;i<N;i++){
    X[i]=vec[i];
  }
  sort(X.begin(),X.end());
  
  int sec=X[N-2];
  
  
  for(int i=0;i<N;i++){
    if(vec[i]!=X[N-1]){
      cout<<X[N-1]<<endl;
    }
    else{
      cout<<sec<<endl;
    }
  }
}