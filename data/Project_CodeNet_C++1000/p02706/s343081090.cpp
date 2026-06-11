#include<bits/stdc++.h>
using namespace std;
  int main(){
    int n,m;
    cin>>n>>m;
    int x=0;
    vector<int>vec(m);
    for(int i=0;i<m; i++){
      cin>>vec.at(i);
      x+=vec.at(i);
    }
    if(x>n){cout<<"-1"<<endl;}
    else {cout<<n-x<<endl;}
  }
    
