#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,n,x;
	cin>>a>>b>>n;
	if(n>=b) x = b-1;
	else x = n;
	cout<<a*x/b-a*(x/b);
}