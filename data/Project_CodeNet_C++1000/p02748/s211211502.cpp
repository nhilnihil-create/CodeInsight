#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int a,b,m;
	cin >> a >> b >> m;
	vector<int> an,bn;
	for (int i = 0; i < a; i++){
		int temp;
		cin >> temp;
		an.push_back(temp);
	}
	for (int i = 0; i < b; i++){
		int temp;
		cin >> temp;
		bn.push_back(temp);
	}
	int best = 1e9+5;
	for (int i = 0; i< m; i++){
		int x,y,c;
		cin >> x >> y >> c;
		best = min(best, an[x-1]+bn[y-1]-c);
	}
	int mina = *min_element(an.begin(),an.end());
	int minb = *min_element(bn.begin(), bn.end());
	best = min(best, mina+minb);
	cout << best;
	return 0;
}
