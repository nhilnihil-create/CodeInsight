#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n;
vector<vector<double>>v;
vector<double>w;
vector<int>pre;
double inf=1e7;
void solve(){
	for(int i=0;i<n;i++)w.push_back(inf);
	for(int i=0;i<n;i++)pre.push_back(-1);
	w[0]=0;
	int k=0;
	double res=0;
	while(k++!=n){
		// 选一个最小的 
		double mi=inf;
		int id=-1;
		for(int i=0;i<n;i++)
			if(w[i]!=-1&&w[i]<mi)mi=w[i],id=i;
		w[id]=-1;
		for(int i=0;i<n;i++){
			if(w[i]!=-1&&v[id][i]!=-1&&v[id][i]<w[i]){
				w[i]=v[id][i];
				pre[i]=id;
			}
		}
		res+=mi;
	}
	cout<<res<<endl;
}
int main(){
	int t;
	cin>>n;
	for(int i=0;i<n;i++){
		v.push_back(vector<double>());
		for(int j=0;j<n;j++){
			cin>>t;
			v[i].push_back(t);
		}
	}
	solve();	
	return 0;
}
