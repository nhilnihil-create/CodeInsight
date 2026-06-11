#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	int x=(a+d-1)/d; //a=9	d=4 经过变化后正好3次 
	int y=(c+b-1)/b;
	cout<<(x>=y?"Yes":"No")<<"\n";
 } 