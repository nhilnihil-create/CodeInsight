#include<iostream>
#include<algorithm>
using namespace std;


int main (void)
{ 
  long long int ans,a,b,c,d,gcd,lcm;
  
  cin>>a>>b>>c>>d;
  long long int cc=c,dd=d;
  while(1){
  gcd=cc%dd;
  if(gcd==0){gcd=dd;break;}
  else{cc=dd;dd=gcd;}
  }
  lcm=c*d/gcd;
  
  ans=b-a+1;
  ans=ans-b/c-b/d+a/c+a/d;
  if(a%c==0)ans--;
  if(a%d==0&&a%c!=0)ans--;
  ans=ans+b/lcm-a/lcm;
  
  
  cout<<ans<<endl;
  
  return 0;
}

 