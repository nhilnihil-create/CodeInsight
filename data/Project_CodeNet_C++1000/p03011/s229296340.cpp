#include<bits/stdc++.h>
using namespace std;


int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	cout<<a+b+c-max(a,max(b,c));
}