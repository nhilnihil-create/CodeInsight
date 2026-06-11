#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	return !b?a:gcd(b,a%b);
}
int main(){
  	int a;
  	cin>>a;
  	cout<<360/gcd(360,a);
	return 0;
}