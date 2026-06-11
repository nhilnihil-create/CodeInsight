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

const int maxN = 100005;

class TaskE {
private:
	Debugger debugger;

	vector<pair<int,int>> solve(int from, int to){
		vector<pair<int,int>> ans;
		while(from < to){
			ans.push_back({from, to});
			from++;
			to--;
		}
		return ans;
	}

public:
	void solveOne(int it){
		int n, m ;
		cin >> n >> m;
		int mid = (n+1)/2;
		vector<pair<int,int>> ans = solve(1, mid);
		vector<pair<int,int>> ans2;
		if(n & 1){
			ans2 = solve(mid+1,n);
		}else{
			ans2 = solve(mid+2,n);
		}
		for(auto elem : ans){
			if(m == 0){
				break;
			}
			cout << elem.first << " "<<elem.second << endl;
			m--;
		}
		for(auto elem : ans2){
			if(m == 0){
				break;
			}
			cout << elem.first << " "<<elem.second << endl;
			m--;
		}
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
	TaskE solver;
	solver.solve();
	return 0;
}
