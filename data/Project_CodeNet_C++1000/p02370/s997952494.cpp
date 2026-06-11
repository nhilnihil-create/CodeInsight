#include<iostream>
#include<vector>
#define MAXN 10000+5
using namespace std;
vector <int> p[MAXN];
bool jud[MAXN];
int n,m;

void dfs(int i){
	
	int len=p[i].size();
	if (jud[i]) return;
	
	if (len == 0 && !jud[i]) {
		jud[i]=1;
		cout<<i<<endl;
		return;
	}
	
	for (int j = 0;j < len;++j){
		if (!jud[p[i][j]]) {
			dfs(p[i][j]);	
		}
	}
	if (!jud[i]){
		jud[i]=1;
		cout<<i<<endl;
	}
}

int main(){
	int a,b,i,j;
	cin>>n>>m;
	for (i = 0;i < m;++i){
		cin>>a>>b;
		p[b].push_back(a);
	}
	for (i = 0;i < n;++i){
		if (p[i].size() == 0 && !jud[i]){
			jud[i]=1;
			cout<<i<<endl;
		}
		else dfs(i);
	}
	return 0;
} 