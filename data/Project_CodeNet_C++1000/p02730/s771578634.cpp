#include<iostream>
#include<string>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int n=s.size();
  int count=0;
  for(int i=0;i<n;i++){
    if(s[i]==s[n-1-i]){
      count++;
    }
  }
  if(count==n){
    int x=(n-1)/2;
    for(int i=0;i<x;i++){
      if(s[i]==s[x-1-i]){
        count++;
      }
    }
    int y=(n+3)/2;
    for(int i=0;i<n-y+1;i++){
      if(s[y-1+i]==s[n-1-i]){
        count++;
      }
    }
    if(count==n+n+1+x-y){
      cout<<"Yes";
    }
    else{
      cout<<"No";
    }
  }
  else{
    cout<<"No";
  }
  
}
