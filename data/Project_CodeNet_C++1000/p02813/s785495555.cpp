#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int main()
{
	int n;
	int x[8];
	for(int i=0;i<8;i++) x[i]=i+1;
	cin>>n;
	int t=0;
	int A=0,B=0;
	int a[N],b[N];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	while(next_permutation(x,x+n))
	{
		t++;
		int ant=0,bnt=0;
		for(int i=0;i<n;i++)
		{
			if(x[i]==a[i]) ant++;
			if(x[i]==b[i]) bnt++;
		}
		if(ant==n) A=t;
		if(bnt==n) B=t;
	}
	int sum;
	sum=abs(A-B);
	cout<<sum<<endl;
	return 0;
}