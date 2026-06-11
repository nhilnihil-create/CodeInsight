#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;cin>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  int lowest=A.at(0);
  int count=1;
  for(int i=1;i<N;i++){
    if(A.at(i)<lowest){
      lowest=A.at(i);
      count++;
    }
  }
  cout<<count<<endl;
}
