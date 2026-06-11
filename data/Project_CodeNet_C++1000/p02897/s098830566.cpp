#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,p;
 	float a;
 	cin>>n;
 	if(n%2==0)
 		p=n/2;
 	else
 		p=n/2+1;
 	a=float(p)/float(n);
	 cout << fixed << setprecision(6) <<a<<endl; 	
 	return 0;
}
 	
 					