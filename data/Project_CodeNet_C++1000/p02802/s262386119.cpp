#include<iostream>
#include<vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<int>p(n,0),wa(n,0);
	int q,ac=0,w;
	string tmp;
	rep(i,m){
		cin>>q>>tmp;
		if(p[q-1]==0){
			if(tmp[0]=='W')wa[q-1]+=1;
			else {ac++;w+= wa[q-1];p[q-1]=1;}
		}
	}
	cout<<ac<<' '<<w<<endl;

	
	return 0;
}