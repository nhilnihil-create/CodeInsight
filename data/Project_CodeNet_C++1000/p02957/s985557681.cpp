#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define adrep(i,s,n) for (int i=(s);i<(n);i++)
using namespace std;
typedef long long ll;


int main(){

  ll a,b;
  cin>>a>>b;
	
 
  if(a==b){cout<<a<<endl;return 0;}
  
  if((a+b)%2==0){cout<<(a+b)/2<<endl;return 0;}
  
  cout<<"IMPOSSIBLE"<<endl;

}
