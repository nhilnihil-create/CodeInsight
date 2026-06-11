#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int a[26]={0},i,j,c=0;
 string str;
 cin>>str;
  	for(j=65;j<91;j++)
	 {
	 	for (int i = 0; i < str.size(); i++)
 	
 		{
 			if(j==str[i])
			 	a[j-65]++;		
 		
		 }
	 }
 	for(i=0;i<26;i++)
 		{
 			if(a[i]==2)
 				c++;
		 }
		if(c==2)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
 	return 0;
}
 	
 					