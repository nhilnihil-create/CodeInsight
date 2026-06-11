#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	set<pair<int,int> >pos;
	int xx[n+1];
	int yy[m+1];
	vector<int>x;
	vector<int>y;
	int maxx=0;
	int maxy=0;
	for(int i=1;i<=n;++i)
		xx[i]=0;
	for(int i=1;i<=m;++i)
		yy[i]=0;
	for(int i=1;i<=k;++i){
		int a,b;
		cin>>a>>b;
		pos.insert(make_pair(a,b));
		++xx[a];
		++yy[b];
		if(xx[a]>maxx){
			maxx=xx[a];
			x.clear();
			x.push_back(a);
		}
		else if(xx[a]==maxx)
			x.push_back(a);
		if(yy[b]>maxy){
			maxy=yy[b];
			y.clear();
			y.push_back(b);
		}
		else if(yy[b]==maxy)
			y.push_back(b);
	}
	for(int i=0;i<x.size();++i)
		for(int j=0;j<y.size();++j)
			if(pos.count(make_pair(x[i],y[j]))==0){
				cout<<maxx+maxy<<endl;
				return 0;
			}
	cout<<maxx+maxy-1<<endl;
	return 0;
}