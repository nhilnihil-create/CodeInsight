#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int total=0;
  vector<int>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
    total+=vec.at(i);
  }
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  if(vec.at(m-1)>=(double)total/(4*m)){
    cout<<"Yes"<<endl;}
  else{cout<<"No"<<endl;}
}
