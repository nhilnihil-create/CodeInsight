#include <iostream>
using namespace std;


 int main(){
 long long x,n,v,sum=0;
 
 cin >> x >> n;
 
 while(n-->0)
 {
	  cin >> v;
	  sum= sum+v;
 }
 
 if(x-sum>=0)
 {
 	cout << x-sum << endl;
 }
 else
 {
 	cout << "-1" << endl;
 }
 
 
 return 0;
 }







