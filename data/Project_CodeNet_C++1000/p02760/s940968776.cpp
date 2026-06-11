#include <bits/stdc++.h>

#define ll long long
#define ii pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1.0)
#define oo 1000000007
#define loo 10000000000000007

#define prime 1000000007

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int mat[3][3];
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			cin >> mat[i][j];
		}
	}

	int n; cin >> n;
	set<int> a;
	for (int i = 0; i < n; ++i){
		int x; cin >> x;
		a.insert(x);
	}

	for (int i = 0; i < 3; ++i){
		if(a.find(mat[i][0]) != a.end() && 
			a.find(mat[i][1]) != a.end() &&
			a.find(mat[i][2]) != a.end()){
			cout << "Yes\n";
			return 0;
		}
		if(a.find(mat[0][i]) != a.end() && 
			a.find(mat[1][i]) != a.end() &&
			a.find(mat[2][i]) != a.end()){
			cout << "Yes\n";
			return 0;
		}
	}
	if(a.find(mat[0][0]) != a.end() && 
		a.find(mat[1][1]) != a.end() &&
		a.find(mat[2][2]) != a.end()){
		cout << "Yes\n";
		return 0;
	}
	if(a.find(mat[2][0]) != a.end() && 
			a.find(mat[1][1]) != a.end() &&
			a.find(mat[0][2]) != a.end()){
			cout << "Yes\n";
			return 0;
		}

		cout << "No\n";



	
	return 0;
}