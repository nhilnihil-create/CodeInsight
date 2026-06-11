#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a, b, c, d;
  cin>>a>>b>>c>>d;
  int k=0;
  while(a>0 && c>0){
  	if(k%2 == 0){
  		c-=b;
  		k++;
  	}
  	else{
  		a-=d;
  		k++;
  	}
  }
  if(a<=0)
  	cout<<"No";
  else
  	cout<<"Yes";
  return 0;
}