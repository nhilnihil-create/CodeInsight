#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,c;
  cin>>a>>b>>c;
  if((a+b)-c > 0){cout<<"No"; return 0;}
  if(((a+b-c)*(a+b-c))>(4*a*b))cout<<"Yes";
  else cout<<"No";
  
}