#include<bits/stdc++.h>
#define mp make_pair
#define print(a) cout<<"print\n";for(pii i:a) cout<<i.first<<" "<<i.second<<"\n"
using namespace std;
typedef pair<int,int> pii;	
typedef long long ll;
pii p[300001];
int X[300001];
int Y[300001];
int main()
{

	int h,w,m;
	while(cin>>h>>w>>m)
	{
		memset(X,0,sizeof(X));
		memset(Y,0,sizeof(Y));
		int maxX=0,maxY=0;
	//	set<pii> v;
	//	set<pii> v2;
		for(int i=0;i<m;i++)
		{
			cin>>p[i].first>>p[i].second;
			//m[p]=1;
			int y=++Y[p[i].first];
			int x=++X[p[i].second];
			maxX=max(x,maxX);
			maxY=max(y,maxY);
		}
		int r=1;
		unordered_map<int,bool> m1,m2;
		ll count=0;
		ll xcount=0,ycount=0;
		for(int i=1;i<=h;i++)
		{
			if(Y[i]==maxY) 
			{
				m1[i]=1;
				ycount++;
			//	cout<<i<<":y\n";
			}
 		}
 		for(int i=1;i<=w;i++)
 		{
 			if(X[i]==maxX)
 			{
 				m2[i]=1;
 				xcount++;
 			//	cout<<i<<":x"<<"\n";
			}
		}
	//	int r=1;
		for(int i=0;i<m;i++)
		{
			int k=m1[p[i].first]+m2[p[i].second];
			if(k==2) {count++;
			}
		}
		
		cout<<maxX+maxY-bool(xcount*ycount==count)<<"\n";
		//pii p[m];
		
	}
}