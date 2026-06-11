#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
  cin>>n;
  int count=0;
  vector<int>vec(n);
  for(int i=0;i<n;i++){
    cin>>vec.at(i);
  }
  sort(vec.begin(),vec.end());
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        if(vec.at(i)==vec.at(j)||vec.at(j)==vec.at(k)||vec.at(k)==vec.at(i)){
          continue;}
        else if((vec.at(k)-vec.at(j))<vec.at(i)){
          count++;
        }
      }
    }
  }
  cout<<count<<endl;
}