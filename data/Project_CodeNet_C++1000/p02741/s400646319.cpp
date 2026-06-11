#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int INF=1e9+5;
const int N=2e3+5;
const int mod=998244353;

int main(){
	ios::sync_with_stdio(0);
	vector<int> a={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	int k;
	cin>>k;
	cout<<a[--k];
	return 0;
}
