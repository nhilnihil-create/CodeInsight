#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin>>N;
  long long rtn=1,an,m18=1e18;
  while(N-->0){
    cin>>an;
    if(an==0){rtn=0;break;}
    else if(rtn<0){continue;}
    else if(m18/rtn<an){rtn=-1;}
    else{rtn*=an;}
  }
  cout<<rtn<<endl;
  return 0;
}