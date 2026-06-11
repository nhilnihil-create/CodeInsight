#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	string a,b ;
	cin>>a>>b ;
	int i,j,min=INT_MAX ;
	for(i=0 ;i+b.size()<=a.size() ;i++)
	{
		int k = i,temp=0 ;
		for(j=0;j<b.size();j++)
		{
			if(a[k]!=b[j])
			  temp++ ;
			k++ ;  
		}
		if(temp<min)
		 min = temp ;
	}
	cout<<min;
	return 0;
}