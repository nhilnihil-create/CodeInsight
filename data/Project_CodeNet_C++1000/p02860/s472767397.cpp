#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  string s;
  cin >>s;
  int p=0;
  if(n%2==0){
    for(int i=0;i<(s.size()/2);++i){
      if(s[i]==s[i+n/2]) p++;
    }
    if(p==n/2) cout <<"Yes"<<endl;
    else cout <<"No"<<endl;
  }
  else cout <<"No"<<endl;
}