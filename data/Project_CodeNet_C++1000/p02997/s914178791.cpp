#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>
using namespace std;
//#define int long long
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long double ld;
typedef long long ll;
#define X first
#define Y second
#define all(o) o.begin(), o.end()
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cin.tie(0)

int gcd(int x,int y){ return (!y ? x : gcd(y, x%y)); }

int32_t main(){
	IOS;
	int n, k;
	cin >> n >> k;
	int mx = n * (n - 1) / 2 - (n - 1);
	if(k > mx)
		cout << -1 << endl;
	else{
		vector<pii> e;
		for(int i=1; i<n; i++)
			e.push_back({0, i});
		int rem = mx - k;
		for(int i=1; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(rem){
					rem--;
					e.push_back({i, j});

				}
			}
		}
		cout << e.size() << endl;
		for(auto t : e)
			cout << t.X+1 << " " << t.Y + 1 << endl;
	}
}
