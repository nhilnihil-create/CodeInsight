#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define adrep(i,s,n) for (int i=(s);i<(n);i++)
using namespace std;
typedef long long ll;

int main(){


  ll a,b,c;
  cin>>a>>b>>c;
 
  if((c-a-b)>0 && 4*a*b<(c-a-b)*(c-a-b)){cout<<"Yes"<<endl;return 0;}
  cout<<"No"<<endl;

}
