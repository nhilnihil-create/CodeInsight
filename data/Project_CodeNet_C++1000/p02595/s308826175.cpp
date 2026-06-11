#include<bits/stdc++.h>
using namespace std;
unsigned long long n,d,x,y,s;
int main(){
	cin>>n>>d;
	while(n--){
		cin>>x>>y;
		if(sqrt(x*x+y*y)<=d)s++;
	}
	cout<<s;
	return 0;
}