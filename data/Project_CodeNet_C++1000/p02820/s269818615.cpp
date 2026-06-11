#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,k,r,s,p;
  string t;
  cin >>n>>k>>r>>s>>p>>t;
  long long sum=0;
  for(int i=0;i<t.size();i++){
    if(t[i]=='r')sum+=p;
    else if(t[i]=='s')sum+=r;
    else sum+=s;
  }
  for(int i=0;i<t.size()-k;i++){
    if(t[i]=='r'&&t[i+k]=='r'){
      sum-=p;
      t[i+k]='a';
    }else if(t[i]=='s'&&t[i+k]=='s'){
      sum-=r;
      t[i+k]='b';
    }else if(t[i]=='p'&&t[i+k]=='p'){
      sum-=s;
      t[i+k]='c';
    }
  }
  cout<<sum<<endl;
  return 0;
}