#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int pow2n = 1 << n; 
	multiset<int> ms;
	rep(i, pow2n) {
		int x;
		cin >> x;

		ms.insert(x);
	}

	vector<int> v;
	auto itr = ms.end();
	itr--;
	v.push_back(*itr);

	rep(i, n){
		vector<int> w = v;
		for(int x : w){
			auto itr = ms.lower_bound(x);
			if(itr == ms.begin()){
				puts("No");
				return 0;
			}
			itr--;

			v.push_back(*itr);
			ms.erase(itr);
		}
	}

	puts("Yes");
}
