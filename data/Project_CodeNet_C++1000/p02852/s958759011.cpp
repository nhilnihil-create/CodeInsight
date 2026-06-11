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

void print(set<int> a){
	for (auto x:a)
		cout << x << " ";
	cout << endl;
}

long long int f(long long int mid, long long int a, long long int b){
	long long int p = a * mid;
	int d = 1;
	while (mid / 10)
	{
		d++;
		mid /= 10;
	}
	p += b * d;
	return p;
}

//深さ優先探索のテンプレ.デフォルトでは参照渡ししたsetに探索済みの頂点が格納される.
//graphは隣接リスト.vは探索開始地点.seenは空のセット
void dfs(vector<vector<pair<int, int>>> &graph, vector<int> &ans, int v, int c = -1, int p = -1)
{
	int k = 1;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int nxt = graph[v][i].first;
		int ei = graph[v][i].second;
		if (nxt == p) continue;
		if (k == c)
			k++;
		ans[ei] = k;
		dfs(graph, ans, nxt, k, v);
		k++;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	reverse(all(s));
	vector<int> ans;
	int now = 0;
	while(now != n)
	{
		int step = min(m,n-now);
		while(s[now+step] == '1')
			step--;
		if(step == 0){
			cout << -1 << endl;
			return 0;
		}
		ans.push_back(step);
		now += step;
	}
	reverse(all(ans));
	print(ans);

	return 0;
}