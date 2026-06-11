#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	auto l = vector<int>(n);
	for(auto&& ll : l) cin >> ll;
	sort(l.begin(), l.end());
	int ans = 0;
	for(int i = 0; i < n - 2; ++i){
		int a = l[i];
		for(int j = i + 1; j < n - 1; ++j){
			int b = l[j];
			if(a == b) continue;
			for(int k = j + 1; k < n; ++k){
				int c = l[k];
				if(b == c) continue;
				if(c < a + b) ++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}