#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    while(b!=0){
      int r = a%b;
      a = b;
      b = r;
    }
    return a;
  }
int main()
{
  int p,s=0,b,c,i;
  cin>>p;

  for ( i=1;i<=p;i++){
    for ( b=1;b<=p;b++){
      for ( c=1;c<=p;c++){
        s=s+gcd(gcd(i,b),c);
      }
    }
  }
  cout<<s<<endl;
  return 0;

}
