#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,r,c,i,ir;
	cin>>n>>r;
	if(n>=10){
		cout<<r<<endl;
	}
	else{
		k=n;
		c=10-k;
		i=100*c;
		ir=r+i;
		cout<<ir<<endl;
	}
}