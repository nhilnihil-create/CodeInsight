#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int k;
  string s;
  cin>>k>>s;
  int n=s.size();
  if(n<=k){
    cout<<s<<endl;
  }
  else{
    for(int i=0;i<k;i++){
      cout<<s.at(i);
    }
    cout<<"..."<<endl;
  }
  
}