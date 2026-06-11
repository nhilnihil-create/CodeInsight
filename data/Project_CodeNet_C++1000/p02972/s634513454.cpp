#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	int n;
	cin >> n;
	vector<int> a(n+1); // 1-based
	REP(i,n) cin >> a[i+1];
	
	int count=0;
	vector<int> ans(n+1,0);
	for(int i=n; i>=1; i--){
		int sum=0;
		for(int j=2; i*j<=n; j++){
			sum = (sum+ans[i*j])%2;
		}
		
		if(sum!=a[i]){
			ans[i]=1;
			count++;
		}
	}
	
	cout << count << endl;
	REP(i,n){
		if(ans[i+1]==1){
			cout << i+1 << " ";
		}
	}
	cout << endl;
	
	return 0;
}