#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;s="0"+s;
  int f=0,cnt=0;
  for(int i=s.size()-1;i>0;i--){
    int d=s[i]-'0'+f;
    int m=min(d,10-d);
    cnt+=m;
    f=(d>5||d==5&&s[i-1]-'0'>=5);
  }
  cout<<cnt+f<<endl;
  return 0;
}