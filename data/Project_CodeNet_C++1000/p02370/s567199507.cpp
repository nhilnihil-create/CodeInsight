#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<iomanip>
#include<cctype>
#include<map>
#include<cstring>
#include<bitset>
#include<cassert>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,a,b) for (int (i)=a;(i)<(b);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long int;

const int inf = 1001001000;
const long long int Inf = 1001001001001001000;



void print(vector<vector<int>> a){
	for (int i = 0; i < a.size(); i++)
	{
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<vector<long long int>> a){
	for (int i=0;i<a.size();i++){
		for (int j=0;j<a[i].size();j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(vector<long long int> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

//トポロジカルソートの結果を返す関数.graphは隣接リスト.0-origin.
//閉路がある場合，空のvectorを返す.
vector<int> tsort(const vector<vector<int>> &graph){
	const int v = graph.size();
	vector<int> indeg(v, 0);
	vector<int> s;
	for (auto out : graph)
	{
		for (auto x:out){
			indeg[x]++;
		}
	}
	for (int i = 0; i < v; i++){
		if(indeg[i] == 0){
			s.push_back(i);
		}
	}
	vector<int> res;
	while(s.size()){
		int u = s.back();
		s.pop_back();
		res.push_back(u);
		for(auto x:graph[u]){
			indeg[x]--;
			if(indeg[x] == 0){
				s.push_back(x);
			}
		}
	}
	if (res.size() != v)
		return vector<int>();
	return res;
}

int main(){
	int v, e;
	cin >> v >> e;
	vector<vector<int>> graph(v);
	rep(i,e){
		int s, t;
		cin >> s >> t;
		graph[s].push_back(t);
	}
	vector<int> ans = tsort(graph);
	print(ans);

	return 0;
}
