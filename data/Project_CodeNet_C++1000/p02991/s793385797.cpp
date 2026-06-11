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

//幅優先探索のテンプレ.デフォルトではstartからの距離を返す.
//graphは隣接リスト.startは探索開始地点
vector<vector<int>> bfs(vector<vector<int>> &graph, int start){
	vector<vector<int>> dist(graph.size(), vector<int>(3, -1));
	queue<pair<int,int>> todo;
	dist[start][0] = 0;
	todo.push(make_pair(start,0));
	while(!todo.empty()){
		int now = todo.front().first;
		int l = todo.front().second;
		todo.pop();
		for (int i=0;i<graph[now].size();i++){
			int nxt = graph[now][i];
			if (dist[nxt][(l+1)%3] != -1) continue;
			dist[nxt][(l+1)%3] = dist[now][l] + 1;
			todo.push(make_pair(nxt,(l+1)%3));
		}
	}
	return dist;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	rep(i, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
	}
	int s, t;
	cin >> s >> t;
	s--;
	t--;
	vector<vector<int>> dist = bfs(graph, s);
	if(dist[t][0] != -1)
		dist[t][0] /= 3;
	cout << dist[t][0] << endl;

	return 0;
}