#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int solve(vector<int> &vec,int n){
  int x=0;
  int m=n-1;
  for(int i=0;i<n;i++){
    if(vec[i]==1){
      x+=((m&i)==i);
    }
  }
  return x%2;
}

int main(){
  int n;
  cin>>n;
  vector<int> vec(n);
  int count=0;
  int z=1;
  string s;
  cin>>s;
  
  for(int i=0;i<n;i++){
    if(s.at(i)=='1'){
      vec[i]=0;
    }
    if(s.at(i)=='2'){
      vec[i]=1;
      count++;
    }
    if(s.at(i)=='3'){
      vec[i]=2;
    }
  }
  
  if(count==0){
    for(int i=0;i<n;i++){
      vec[i]/=2;
    }
    z++;
  }
  
  cout<<solve(vec,n)*z<<endl;
}