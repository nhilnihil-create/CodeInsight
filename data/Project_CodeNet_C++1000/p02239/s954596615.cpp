#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void InputSet(std::vector<int> & a) {
	int n;
	cin >> n;
	a.resize(n,0);
	for(int i=0;i<n;++i) {
		cin >> a.at(i);
		a.at(i)--;
	}
}
void BFS(vector<vector<int> > & Ad,
		 vector<int> & V,
		 queue<int> & Q
		 )
{
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(int i=0;i<(int)Ad[u].size();++i) {
			int next = Ad[u][i];
			if (V[next] < 0) {
				V[next] = V[u] + 1;
				Q.push(next);
			}
		}
	}
}
int main(){
	int n;
	cin >> n;
	vector<vector<int> > Ad(n);
	vector<int> V(n,-1);
	queue<int> Q;
	for(int k=0;k<n;++k) {
		int u;
		cin >> u;
		--u;
		InputSet(Ad[u]);
	}
	Q.push(0);
	V[0]=0;
	BFS(Ad,V,Q);

	for(int i=0;i<n;++i){
		cout << i + 1 << " " << V[i] << endl;
	}
}