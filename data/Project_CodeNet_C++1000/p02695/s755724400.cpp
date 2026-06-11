#include<bits/stdc++.h>
using namespace std;
#define mkp make_pair
typedef long long ll;
typedef pair<ll,ll> P;
int main()
{
	ll n,m,q;
	cin>>n>>m>>q;
	vector<int> A,B,C,D;
	for(int i=0;i<q;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--;
		b--; 
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	int ma = -1234;
	for(int a=1;a<=m;a++)
		for(int b=a;b<=m;b++)
			for(int c=b;c<=m;c++)
			for(int d=c;d<=m;d++)
			for(int e=d;e<=m;e++)
			for(int f=e;f<=m;f++)
			for(int g=f;g<=m;g++)
			for(int h=g;h<=m;h++)
			for(int i=h;i<=m;i++)
			for(int j=i;j<=m;j++)
			{
				vector<int> now;
				int by = n;
				int all[10] = {a,b,c,d,e,f,g,h,i,j};
				while(by>0)
					now.push_back(all[10-by]) , by--;
				int sum = 0;
				for(int pos = 0;pos<q;pos++)
				{
					ll tmp = now[pos];
					ll p1,p2;
					p1 = now[A[pos]];
					p2 = now[B[pos]];
					if(p2-p1 == C[pos])
						sum+=D[pos]; 
				}
				ma = max(ma,sum);
			}
	cout<<ma<<endl;
	return 0; 
}
