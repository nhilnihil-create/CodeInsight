#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
const int maxn=60;
string A,B;
int Next[maxn];

void getnext()
{
	int j=0,k=-1;
	Next[0]=-1;
	while(j<B.size())
	{
		if(k==-1 || B[j]==B[k])
		{
			j++,k++;
			Next[j]=k;
		}
		else k=Next[k];
	}
}

int KMP()
{
	int i=0,j=0,cnt=0;
	while(i<A.size())
	{
		if(j==-1 || A[i]==B[j])
		{
			i++,j++;
		}
		else j=Next[j];
		if(j==B.size())
		{
			cnt++,j=0;
		}
	}
	return cnt;
}

int main()
{
	ios;
	int N;
	cin>>N>>A;
	B="ABC";
	getnext();
	cout<<KMP()<<"\n";
	return 0;
}