#include<bits/stdc++.h>
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
	ios::sync_with_stdio(0);
	int k, x;
	cin >> k >> x;
	for(int i=x-k+1; i<x+k; ++i)
		cout << i << " ";
	cout << endl;
}
