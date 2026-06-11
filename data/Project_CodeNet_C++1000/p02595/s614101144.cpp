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

#define ll long long
const int maxN = 100005;
const ll INF = 1000000000000000000LL;

class TaskB {
private:
	Debugger debugger;

public:
	void solveOne(int it){
		int n;
		cin >> n;
		ll d;
		cin >> d;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			ll x, y;
			cin >> x >> y;
			if(x*x + y*y <= d*d) {
				ans++;
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
	TaskB solver;
	solver.solve();
	return 0;
}
