#include <bits/stdc++.h>
using namespace std;

int main(){
int N;
  cin>>N;
  vector<int>moji(N);
  for(int i=0;i<N;i++){
  cin>>moji.at(i);
  }
  bool nazo=true;
  sort(moji.begin(),moji.end());
  for(int i=0;i<N-1;i++){
  	if(moji.at(i)==moji.at(i+1)){
    nazo=false;
    }
  }
  if(nazo){
  cout<<"YES"<<endl;
  }
  else{
  cout<<"NO"<<endl;
  }
}
