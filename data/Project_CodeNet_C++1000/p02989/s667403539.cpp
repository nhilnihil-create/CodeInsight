#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	vector<int> d(N);
	rep(i,N) cin >> d[i];
	sort(d.begin(),d.end());
	cout << d[N/2] - d[(N-1)/2] << endl;


}












