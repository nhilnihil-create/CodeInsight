#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int num=0;
	if(n%2==0) n--;	//可以都转变成奇数构造，因为m <= (n-1)/2;
	for(int i=1;i<=n/4&&num<m;i++){		//前一半
		cout<<i<<" "<<n/2-i+1<<"\n";
		num++;
	}
	for(int i=n/2+1,j=0;num<m;i++,j++){		//后一半，题目保证m是合法的，所以可以直接num < m
		cout<<i<<" "<<n-j<<"\n";
		num++;
	}
	return 0;
}
