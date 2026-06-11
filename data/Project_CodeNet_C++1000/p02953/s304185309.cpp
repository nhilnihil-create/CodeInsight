#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h.at(i);

	reverse(h.begin(), h.end());

	bool res = true;
	rep(i, n-1){
		if(h.at(i) >= h.at(i+1)) continue;
		else if(h.at(i) == h.at(i+1)-1) h.at(i+1) -= 1;
		else{
			res = false;
			break;
		}
	}

	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;

}
