#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin>>N;
  vector<int> vec(N);
  for(int i=0;i<N;i++){
    cin>>vec.at(i);
  }
  reverse(vec.begin(),vec.end());
  for(int i=1;i<N;i++){
    if(vec.at(i-1)+1<(vec.at(i))){
      cout<<"No"<<endl;
      return 0;
    }
    else if(vec.at(i-1)+1==vec.at(i)) vec.at(i)--;
  }
  cout<<"Yes"<<endl;
  
  
  
}