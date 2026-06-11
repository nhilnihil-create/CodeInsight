#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1e9+7;
// const ll INF = 1000000000000000000LL;
 
 
 int main() {
	 int n;
	 cin >> n;
	 vector<int> x(n);
	 rep(i,n) cin >> x[i];
	 int nin = INF;
	 for(int i=1;i<=100;i++){
		 int cur=0;
		 rep(j,n){
			 cur += pow(x[j]-i,2);
		 }
		 nin = min(cur,nin);
	 }
	 cout << nin << endl;
	 return 0;
 }
