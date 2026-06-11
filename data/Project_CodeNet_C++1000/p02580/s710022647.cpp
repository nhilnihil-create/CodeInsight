#include<bits/stdc++.h>
using namespace std;
int h,w,m,h1,w1,maxr,maxc,row[300005],col[300005];
vector<int> vr;
vector<int> vc;
set<pair<int,int> > st;
int main(){
	cin>>h>>w>>m;
	for(int i=1;i<=m;i++){
		cin>>h1>>w1;
		st.insert(make_pair(h1,w1));
		row[h1]++;
		if(row[h1]==maxr){
			vr.push_back(h1);
		}
		if(row[h1]>maxr){
			maxr=row[h1];
			vr.clear();
			vr.push_back(h1);
		}
		col[w1]++;
		if(col[w1]==maxc){
			vc.push_back(w1);
		}
		if(col[w1]>maxc){
			maxc=col[w1];
			vc.clear();
			vc.push_back(w1);
		}
	}
	for(vector<int>::iterator it=vr.begin();it!=vr.end();it++)
		for(vector<int>::iterator ite=vc.begin();ite!=vc.end();ite++){
			if(st.find(make_pair(*it,*ite))==st.end()){
				cout<<maxr+maxc<<endl;
				return 0;
			}
		}
	cout<<maxr+maxc-1<<endl;
	return 0;
} 