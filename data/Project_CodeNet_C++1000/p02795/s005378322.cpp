#include<bits/stdc++.h>
using namespace std;
#define forr(i,a,n) for(int i=a; i<n; i++)
#define SPEED ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(0)
int main() 
{
	SPEED; 
	float a,b,c,d;
	cin>>a>>b>>c;
	d=max(a,b);
	cout<<ceil(c/d);
	return 0;
}