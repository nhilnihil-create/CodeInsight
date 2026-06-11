#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+5;
vector<int>ve[N];
priority_queue<int>qe;
int main()
{
	int n,m;
	cin>>n>>m;
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(m-a+1<1)continue;
		ve[m-a+1].push_back(b);
	}
	int anx=0;
	for(int i=m;i>=1;i--){
		for(int j=0;j<ve[i].size();j++){
			qe.push(ve[i][j]);
		}
		if(!qe.empty()){
			anx+=qe.top();qe.pop();
		}
	}
	cout<<anx<<"\n";
}