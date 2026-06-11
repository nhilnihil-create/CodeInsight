#include <bits/stdc++.h>
#define pi 3.14159
#include <map>
#include <iterator>
using namespace std;
int main()
 {
 	long long int w,h,x,y;
 	cin>>w>>h>>x>>y;
 	cout << fixed << setprecision(9) <<w*h/2.0<<" "; 
 	if(2*x==w&&2*y==h)
 		cout<<"1"<<endl;
 	else
 		cout<<"0"<<endl;
 }