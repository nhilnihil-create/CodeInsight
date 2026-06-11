#include <bits/stdc++.h>
using namespace std; 
//解説AC
int main() {
  string s;
  cin >>s;
  int n=s.size();
  vector<long long>a(n);
  a[0]=1;
  if(s[0]==s[1]&&s[1]==s[2]){
    a[1]=1;
    a[2]=2;
  }else if(s[0]==s[1]&&s[1]!=s[2]){
    a[1]=1;
    a[2]=2;
  }else if(s[1]==s[2]&&s[0]!=s[1]){
    a[1]=2;
    a[2]=2;
  }else{
    a[1]=2;
    a[2]=3;
  }
  for(int i=3;i<n;i++){
    if(s[i]==s[i-1]){
      a[i]=a[i-3]+2;
    }else{
      a[i]=a[i-1]+1;
    }
  }
  /*for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }*/
  //cout<<n<<endl;
  cout<<a[n-1]<<endl;
  return 0;
}