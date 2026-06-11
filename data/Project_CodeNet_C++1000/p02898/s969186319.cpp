#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n,k;
  int count=0;
  cin>>n>>k;
  vector<int>a(n);
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    if(a.at(i)>=k){
      count+=1;
    }
    else{
      int unko=0;
    }
  }
  cout<<count<<endl;
}