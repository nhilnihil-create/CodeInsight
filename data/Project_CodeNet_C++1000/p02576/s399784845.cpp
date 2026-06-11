#include<bits/stdc++.h>
using namespace std;
int N,X,T,yu,t;
int main() 
{
    cin>>N>>X>>T;
	if (N<=X) cout<<T;
	  else{
	   yu=(N+X-1)/X; 
	   t=yu*T;
	   cout<<t;
     }
return 0;	
}