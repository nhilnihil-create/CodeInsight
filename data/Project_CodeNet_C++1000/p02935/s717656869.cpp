#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	 int N;
	 cin >> N;
	 vector<int> v(N);
	 for(int i = 0; i < N; ++i) {
		 cin >> v[i];
	 }
	 sort(v.begin(),v.end());
	 double ans = v[0];
	 for (int i = 1; i < N; ++i) {
		 ans += v[i];
		 ans /= 2;
	 }
	 cout << ans << endl;



}












