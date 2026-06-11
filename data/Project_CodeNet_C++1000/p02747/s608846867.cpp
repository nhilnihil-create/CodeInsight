#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"

int main(){
  string s;cin>>s;
  int r=1,N=s.size();
  if(N%2){r=0;}
  else{
    REP(i,N/2){
      if(s[i*2]!='h'||s[i*2+1]!='i'){r=0;break;}
    }
  }
  cout<<(r?Liny:Linn);
}