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

int n, k;
vector<int> seen, connect;
vector<vector<int>> graph;
ll mod = 1e9 + 7;
ll ans = 1;

//深さ優先探索のテンプレ.デフォルトでは参照渡ししたsetに探索済みの頂点が格納される.
//graphは隣接リスト.vは探索開始地点.seenは空のセット.
void dfs(int v,int m,int p=-1){
	seen[v] = 1;
	int t;
	if (p == -1)
		t = k;
	else if (p == 0){
		t = k - 1;
	}
	else {
		t = k - 2;
	}
	t -= m;
	ans = ((ans % mod) * (t % mod)) % mod;
	int a = 0;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int nxt = graph[v][i];
		if (seen[nxt]==1) continue;
		dfs(nxt,a,v);
		a++;
	}
}

int main(){
	cin >> n >> k;
	graph = vector<vector<int>>(n);
	seen = connect = vector<int>(n,0);
	rep(i, n) seen[i] = 0;
	rep(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
		connect[a]++;
		connect[b]++;
	}
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}