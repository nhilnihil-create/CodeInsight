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

const int INF = 1e9;
const int MAXN = 1000005;
#define ll long long

set<int> colsInRows[MAXN];
set<int> rowsInCols[MAXN];

class TaskF {
private:
	Debugger debugger;
	int n;
	ll get(int x, int y){
		int deltax = x+1;
		int deltay = n-y;
		return (ll)deltax * deltay;
	}

public:
	void solveOne(int it){
		cin >> n;
		ll ans = 0;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			if(x > y){
				swap(x, y);
			}
			x--; y--;
			ans -= get(x, y);
		}
		for(int i = 0; i < n; i++){
			ans += get(i, i);
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
	TaskF solver;
	solver.solve();
	return 0;
}
