#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  string A,B;
  cin>>A>>B;
  for(int i=0;i<N*2;i++){
    if(i%2==0){
      cout<<A.at(i/2);
    }
    else if(i%2==1){
      cout<<B.at((i-1)/2);
    }
  }
  cout<<endl;
}
