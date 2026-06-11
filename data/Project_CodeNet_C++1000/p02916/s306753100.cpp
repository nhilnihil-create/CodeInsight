#include <bits/stdc++.h>
using namespace std;

vector<int> ai;
vector<int> bi;
vector<int> ci;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		ai.push_back(a);
	}
	for(int j=0;j<n;j++){
		int b;
		cin>>b;
		bi.push_back(b);
	}
	for(int k=0;k<n;k++){
		int c;
		cin>>c;
		ci.push_back(c);
	}
	int ans=0;
	for(int z=0;z<n;z++){
		ans+=bi[ai[z]-1];
		if(z!=0 && ai[z-1]==ai[z]-1){
			ans+=ci[ai[z-1]-1];
		}
	}
	cout<<ans;
}