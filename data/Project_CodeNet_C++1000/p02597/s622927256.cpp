#include <bits/stdc++.h>
#define bug1(x) cout<<#x<<" = "<<x<<endl
#define bug2(x,y) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl
#define bug3(x,y,z) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<endl
#define bug4(x,y,z,m) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<" "<<#m<<" = "<<m<<endl

using namespace std;

class Debugger {
public:
	template<typename T>
	void printVector(vector<T> const &vec, bool printSize=true){
		if(printSize){
			cout << vec.size() << endl;
		}
		for(auto &elem : vec){
			cout << elem << " ";
		}
		cout << endl;
	}

	template<typename T>
	void printMatrix(vector<vector<T>> const &matrix){
		cout << matrix.size()<< " ";
		if(!matrix.empty()){
			cout << matrix[0].size();
		}
		cout << endl; 
		for(auto &vec : matrix){
			printVector(vec, false);
		}
		cout << endl;
	}
};

const int MAXN = 10000001;
const int INF = 1e9;
#define ll long long 

class TaskD {
private:
	Debugger debugger;
	vector<vector<int>> graph;
	vector<bool> vis;
	int dfs(int u) {
		vis[u] = true;
		int ans = 1;
		for(int nxt : graph[u]) {
			if(!vis[nxt]) {
				ans += dfs(nxt);
			}
		}
		return ans;
	}

public:
	void solveOne(int it){
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector<int> sum(n);
		for(int i = 0; i < n; i++) {
			sum[i] = s[i] == 'R' ? 1 : 0;
			if(i > 0) {
				sum[i] += sum[i-1];
			}
		}
		int ans = n;
		int whites = 0;
		for(int i = 0; i <= n; i++) {
			int reds = sum[n-1] - (i > 0 ? sum[i-1]:0);
			ans = min(ans, reds + whites - min(reds, whites));
			if(i < n && s[i] == 'W') {
				whites++;
			}
		}
		cout << ans << endl;
	}

	void solve(){
		int tc = 1;
		for(int it = 1; it <= tc; it++){
			solveOne(it);
		}
	}
};


int main(){
	ios_base::sync_with_stdio(false);
	TaskD solver;
	solver.solve();
	return 0;
}
