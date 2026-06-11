#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int a,b,c,k,sum=0;
	cin>>a>>b>>c>>k;
	while(b<=a)
	{
		b*=2;
		sum++;
	}
	while(c<=b)
	{
		c*=2;
		sum++;
	}
	if(k>=sum)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}


