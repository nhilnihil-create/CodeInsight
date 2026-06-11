#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  n=s.size();
  if(n%2==0){
    if(s.substr(0,n/2)==s.substr(n/2,n/2)){
      cout<<n/2<<endl;
      return 0;
    }
  }
  if(n<=26){
    string t=s;
    sort(t.begin(),t.end());
    int flag=0;
    for(int i=0;i<n-1;i++){
      if(t[i]==t[i+1]){
        flag++;
      }
    }
    if(flag==0){
      cout<<0<<endl;
      return 0;
    }
  }
  int ng=(n+1)/2;
  int ok=0;
  string t;
  int check,flag;
  while(!(ng-ok==1)){
    check=(ok+ng)/2;
    flag=0;
    for(int i=0;i<n-check;i++){
      t=s.substr(i,check);
      for(int j=i+check;j<n;j++){
        if(t[0]!=s[j]||t[1]!=s[j+1]){
          continue;
        }
        if(t==s.substr(j,check)){
          flag=1;
          break;
        }
      }
      if(flag==1){
        break;
      }
    }
    if(flag==0){
      ng=check;
    }
    else{
      ok=check;
    }
  }
  cout<<ok<<endl;
}