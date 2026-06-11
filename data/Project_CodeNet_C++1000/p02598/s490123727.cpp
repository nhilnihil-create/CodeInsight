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
const int MAXN = 1000005;
const int MOD = 1000000007;

class TaskE {
private:
	Debugger debugger;

	bool possible(double limit, const vector<int> &nums, int k) {
		ll needed = 0;
		for(int c : nums) {
			needed += ceil((double)c / limit) - 1;
		}
		return needed <= k;
	}

public:
	void solveOne(int it){	
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);
		for(int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		double le = 0, ri = 1e9;
		for(int it = 0; it < 100; it++) {
			double mid = (le+ri)/2;
			if(possible(mid, nums, k)) {
				ri = mid;
			} else {
				le = mid;
			}
		}
		ll ans = ceil(ri);
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
	TaskE solver;
	solver.solve();
	return 0;
}

