#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
   int n, j=0,x,p=0;
   cin>>n;
   string s;
   cin>>s;
   while(j<(n-2)){
   	if(s[j]=='A' && s[j+1]=='B' && s[j+2]=='C')
   	{
   		p++;
   		j=j+3;
   	}
   	else
   	j++;
   }
   cout<<p;
	return 0;
}