#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  string s=to_string(n);
  int i=s.length()-1;
  int rrr=9,ans=0;
  int j=1;
  while(j<=i){
    ans+=rrr;
    j+=2;
    rrr=rrr*100;
  }
  int kkk=1;
  if(i%2==0){for(int k=0;k<i;k++)kkk*=10;
  ans+=n-kkk+1;
  }
  cout<<ans<<endl;
}