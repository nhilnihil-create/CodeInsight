#include "bits/stdc++.h"

using namespace std;

using ll = long long;
#define all(x) begin(x), end(x)

int main(){
ios_base::sync_with_stdio(0); cin.tie(0);
int64_t K, N;
	cin >> K >> N;
	vector<int64_t> vec(N);
	vector<int64_t> len(N);
	
	for (int i = 0; i < N ; i++)
	{
		cin >> vec.at(i);
	}
	 int64_t ans= abs(vec.at(0) - 0) + abs(K - vec.at(N - 1));
	 for (int i = 1; i < N; i++)
	 {
		 ans = max(ans, vec.at(i) - vec.at(i - 1));
	 }
	 cout << K-ans << endl;

}
