#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int>a(N);
  for(int i=0; i<N; i++){
    cin>>a.at(i);
  }
  
  bool ans = true;
  for(int x : a){
    if(x%2 == 0 && x%3!=0 && x%5!=0){
      ans = false;
      break;
    }
  }
  if(ans) cout<<"APPROVED"<<endl;
  else cout<<"DENIED"<<endl;
}