#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  string S;
  cin>>N>>M>>S;
  vector<int> p(N+1,-1);
  p.at(0)=0;
  for(int i=0;i<N;i++){
    if(p.at(i)==-1){
      continue;
    }
    else{
      for(int j=min(M,N-i);j>0;j--){
        if(p.at(j+i)==-1&&S.at(j+i)=='0'){
          p.at(j+i)=i;
        }
        else if(S.at(j+i)=='0'){
          break;
        }
      }
    }
  }
  if(p.at(N)==-1){
    cout<<"-1"<<endl;
  }
  else{
    
    vector<int> z;
    int A=N;
    while(A!=0){
      z.push_back(A-p.at(A));
      A=p.at(A);
    }
    reverse(z.begin(), z.end());
    int q=z.size();
    for(int i=0;i<q;i++){
      cout<<z.at(i);
      if(i!=q-1){
        cout<<" ";
      }
      else{
        cout<<endl;
      }
    }
  }
}