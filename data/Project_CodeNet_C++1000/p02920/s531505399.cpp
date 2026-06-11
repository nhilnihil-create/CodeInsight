//  ROAD TO GREEN
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <queue>
#include <set>
#include <bitset>

#define ll long long
#define uint unsigned int
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define all(x) x.rbegin(), x.rend()
#define speedhack() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool cmp(int a, int b){
	return a > b;
}

using namespace std;
const ll MAXN = 2e9+2;
const ll SIZE = 1e6+2;
const ll mod = 1e9+7;
int a[SIZE];

int main(){ 
	speedhack()
	int k; cin >> k;
	int n = (1 << k);

	multiset<int> data;

	for(int i = 1; i <= n; i++){
		int cur; cin >> cur;
		data.insert(cur*-1);
	}
	vector<int> vals;
	vals.push_back(*(data.begin()));
	data.erase(data.begin());
	for(int it = 1; it <= k; it++){
		vector<int> newv;
		for(int i = 0; i < vals.size(); i++){
			if(data.upper_bound(vals[i]) == data.end()){
				cout << "No" << endl;
				return 0;
			}
			newv.push_back(*(data.upper_bound(vals[i])));
			data.erase(data.upper_bound(vals[i]));
		}
		for(int i = 0; i < newv.size(); i++){
			vals.push_back(newv[i]);
		}
		sort(all(vals));
	}
	cout << "Yes" << endl;
	return 0;
}





