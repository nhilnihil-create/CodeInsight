#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int a,b,c;
 	cin>>a>>b>>c;
 	if(a==b&&b==c)
 		cout<<"No"<<endl;
 	else if(a==b||b==c||c==a)
 		cout<<"Yes"<<endl;
 	else
	 	cout<<"No"<<endl;	
 	
 	return 0;
}
 	
 					