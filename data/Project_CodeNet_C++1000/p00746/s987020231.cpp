#include <bits/stdc++.h>
using namespace std;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int main(){
	int n;
	while(cin>>n,n){
		vector<pair<int,int> > fld;
		fld.push_back(make_pair(0,0));
		int a,b;
		for(int i=1;i<n;i++){
			cin>>a>>b;
			fld.push_back(make_pair(fld[a].first+dx[b],fld[a].second+dy[b]));
		}
		int xr=0,xl=0,yu=0,yd=0;
		for(int i=1;i<n;i++){
			int x=fld[i].first,y=fld[i].second;
			xr=max(xr,x);
			xl=min(xl,x);
			yu=min(yu,y);
			yd=max(yd,y);
		}
		cout<<xr-xl+1<<" "<<yd-yu+1<<endl;
	}
}