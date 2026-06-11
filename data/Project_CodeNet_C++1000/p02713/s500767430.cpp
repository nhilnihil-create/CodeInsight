#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<=(n);i++)



int gcd2(int a,int b)
{
	if(a==0) 
      return b;
  return gcd2(b % a,a);//ユークリッドの互除法を実装してます
}

int gcd(int a,int b,int c)
{
	return gcd2(a,gcd2(b,c));
}

int main() {
	int k;
	cin>>k;
  	
  	ll sum=0;
  	for(int d=1;d<=k;d++){
      for(int e=1;e<=k;e++){
        for(int f=1;f<=k;f++){
          sum += gcd(d,e,f);//abcにすると上とかぶるからだめなのね
        }
      }
    }
  
  cout<<sum;
  return 0;
}