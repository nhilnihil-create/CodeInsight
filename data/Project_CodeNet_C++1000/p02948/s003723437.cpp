#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
priority_queue<int> qe;
vector<int> ve[N]; 
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a,b;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		if(m-a+1<1)continue;
		ve[m-a+1].push_back(b);
	}
	int anx=0;
	for(int i=m;i>=1;--i){
		for(int j=0;j<ve[i].size();++j){
			qe.push(ve[i][j]);
		}
		if(!qe.empty()){
			anx+=qe.top();
			qe.pop();
		}
	}
	printf("%d",anx);
}