#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
int main()
{
  using namespace std;
  string s;
  cin>>s;
  string tmp="\0";
  int i;
  rep(i,5){
    tmp+="hi";
    if(s.compare(tmp)==0){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}
