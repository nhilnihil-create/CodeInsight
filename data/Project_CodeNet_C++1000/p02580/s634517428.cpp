#include<bits/stdc++.h>
using namespace std;
int a[300005],b[300005];
set<pair<int,int> > st;
vector<int> l,r;
int main(){
	int h,w,m,x,y,maxa=0,maxb=0;
	cin>>h>>w>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		st.insert(make_pair(x,y));
		a[x]++; b[y]++;
		if(a[x]>maxa){
			l.clear(); maxa=a[x];
		}
		if(a[x]==maxa) l.push_back(x);
		if(b[y]>maxb){
			r.clear(); maxb=b[y];
		}
		if(b[y]==maxb) r.push_back(y);
	}
	int p=l.size(),q=r.size();
	for(int i=0;i<p;i++){
		for(int j=0;j<q;j++){
			if(st.find(make_pair(l[i],r[j]))==st.end()){
				cout<<maxa+maxb;
				return 0;
			}
		}
	}
	cout<<maxa+maxb-1;
	return 0;
}