#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
 int n, k;
 cin >> n >> k;
 vector<int> d(n);
 rep(i,k){
 	int m;
 	cin >> m;
 	rep(j,m){
 		int a;
 		cin >> a;
 		d.at(a-1) = 1;
 	}
 }
 int ans = 0;
 rep(i,n) if(d.at(i) == 0) ans++;
 cout << ans << endl;
}