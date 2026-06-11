#include<bits/stdc++.h>
using namespace std;
long long x;
__int128 ans=1; 
long long a[100005];
void print(__int128 x)
{
	if (!x) return ;
	if (x < 0) putchar('-'),x = -x;
	print(x / 10);
	putchar(x % 10 + '0');
}
int main()
{
	long long a;
	string b;
	cin>>a>>b;
	int x1=(b[0]-48)*100;
	int x2=(b[2]-48)*10;
	int x3=(b[3]-48);
	int x=x1+x2+x3;
//	cout<<x<<endl;
	cout<<a*x/100; 
}