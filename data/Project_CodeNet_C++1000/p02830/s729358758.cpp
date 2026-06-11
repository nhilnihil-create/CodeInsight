#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  string A,B;
  cin>>A>>B;
  string ans;
  for(int i=0;i<N;i++){
    cout<<A.at(i)<<B.at(i);
  }
  return 0;
}
