#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;
const int INFTY = (1 << 21); // 2097152
// const ll INFTY = (1LL << 60);

int N;
int a[100000];
int main() {
	cin >> N;
	rep(i, N) cin >> a[i];

	vint vec;
	rep(i, N){
		if(i == 0) vec.push_back(a[i]);
		else{
			if(a[i] > vec[vec.size()-1]) vec.push_back(a[i]);
			vint::iterator it = lower_bound(vec.begin(), vec.end(), a[i]);
			*it = a[i];
		}
	}
	cout << vec.size() << endl;
}