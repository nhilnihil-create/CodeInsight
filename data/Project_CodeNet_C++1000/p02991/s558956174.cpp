
#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n,m;cin>>n>>m;
	vector<int> u(m),v(m);
	vector<vector<int>> uv(n);
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i];
		u[i]--;v[i]--;
		uv[u[i]].push_back(v[i]);
	}
	int s,t;cin>>s>>t;
	s--;t--;
	int hop=0;
	vector<vector<int>> used(n,vector<int>(3,0));
	vector<int> tempn;
	tempn.push_back(s);
	used[s][0]=1;
	while(tempn.size()){
		vector<int> nextn;
		hop++;
		for(int i=0;i<tempn.size();i++){
			for(int j=0;j<uv[tempn[i]].size();j++){
				if(used[uv[tempn[i]][j]][hop%3]==0){
					nextn.push_back(uv[tempn[i]][j]);
					used[uv[tempn[i]][j]][hop%3]=1;
					if(uv[tempn[i]][j]==t){
						if(hop%3==0){
							cout<<hop/3<<endl;
							return 0;
						}
					}
				}
			}

		}
		tempn=nextn;

	}
	cout<<-1<<endl;


	return 0;
}