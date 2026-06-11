#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin>>n;
  n=n%10;
  if(n==3){
    cout<<"bon"<<endl;
  }
  else if(n<2||n==6||n==8){
    cout<<"pon"<<endl;
  }
  else{
    cout<<"hon"<<endl;
  }

  
}