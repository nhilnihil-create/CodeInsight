#include<iostream>
#include<set>
using namespace std;
int par[100007];
int find(int i){
	if(i != par[i]) return par[i] = find(par[i]);
	else return par[i];
}
void setPar(int a,int b){
	par[find(a)] = find(b);
}
int main(){
	ios::sync_with_stdio(false);
	int n,m;cin >> n >> m;
	for(int i = 1;i <= n;++i) par[i] = i;
	for(int i = 0;i < m;++i){
		int a,b;cin >> a >> b;
		setPar(a,b);
	}
	set<int> xx;
	for(int i = 1;i <= n;++i) xx.insert(find(i));
	cout << xx.size()-1;
	return 0;
}