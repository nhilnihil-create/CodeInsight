#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long A,B,C,k,q,w;
	cin>>A>>B>>C>>k;
	int  a=A,b=0,c=C*-1;
	if(A>=k)  cout<<k;
	else if(A+B+C==k) cout<<a+c;
	else{
		q=k-A;
		if(B>=q) cout<<a;          
		else 
		{
			w=q-B;
			w=w*-1;
			cout<<a+w;
		}
	} 
}