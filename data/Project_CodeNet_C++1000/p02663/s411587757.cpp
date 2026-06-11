#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using Graph = vector< vector<int> >;

int main(){
	int h1,h2,m1,m2,k;
	cin >> h1 >> m1 >> h2 >> m2 >> k; 
	int h,m,t;
	h = h2-h1;
	m = m2-m1;
	t = h*60+m;
	cout << t - k << endl;
}