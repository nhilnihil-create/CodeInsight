#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5000000+10;
int m,d;
int main()
{
	cin>>m>>d;
	int cnt=0;
	for(int i=0;i<=d;i++)
	{
		int ys=i%10;
		int zs=i/10;
		if(ys<2||zs<2)
		continue;
		if(ys*zs<=m)
		cnt++;
	}
	cout<<cnt<<endl;
}