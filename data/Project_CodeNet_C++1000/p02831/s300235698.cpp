#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	long long x,y;
	cin>>x>>y;
	
	long long g = __gcd(x,y);
	cout<<x*y/g;
	
	return 0;
}
