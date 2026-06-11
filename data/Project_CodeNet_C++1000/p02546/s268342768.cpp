#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>
#include<stack>
#include<map>
#include<math.h>
using namespace std;
 
 
 
int main()
{
	
	string a;
	cin>>a;
	if(a[a.length()-1]=='s'){
		a+="es";
	}else{
		a+="s";
	}
 
 	cout<<a;
	
	return 0;
}