#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  set<int> s;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    s.insert(a);
  }
  int M=s.size();
  if(N==M){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}