#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
 
const double PI = acos(-1);
 
int main() {
	int N;
    cin >> N;
    int v[N] = {};
    int a;
    rep(i,N-1) {
    	cin >> a;
        v[a-1]++;
    }
    rep(i,N) {
    	cout << v[i] << "\n";
    }
    return 0;
}