#include<bits/stdc++.h>
using namespace std;
int main(){
	unsigned long a,b,c;
   cin>>a>>b>>c;
  if(4*a*b<(c-a-b)*(c-a-b) && a+b<c)
   cout<<"Yes";
	else
 cout<<"No";
 return 0;
}