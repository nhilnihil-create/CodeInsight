#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)



int main() {
	int n,i=0,j=0,k=0,ans=0,ans2=0;
	vector<vector <int >> a(3, vector< int>(3));

	rep(i, 3) {
		rep(j, 3) {
			cin >> a.at(i).at(j);
		}
	}

	cin >> n;
	vector<int > b(n);

	rep(k, n) {
		cin >> b.at(k);
		rep(i, 3) {
			rep(j, 3) {
				if (a.at(i).at(j) == b.at(k)) {
					a.at(i).at(j) = 0;
					
				}
				
			}
			
		}

	}
	rep(i, 3) {
		rep(j, 3) {
			if (a.at(i).at(j) == 0) {
				ans++;
				if (ans == 3) {
					ans2++;
				}
			}
		}
		ans = 0;
	}

	rep(i, 3) {
		rep(j, 3) {
			if (a.at(j).at(i) == 0) {
				ans++;
				if (ans == 3) {
					ans2++;
					//cout << ans2 << "b" << endl;
				}
			}

		}
		ans = 0;
	}
	rep(i, 3) {
		if (a.at(i).at(i) == 0) {
			ans++;
			if (ans == 3) {
				ans2++;
				//cout << ans2 << "b" << endl;
			}
		}
	
	}
	ans = 0;
	rep(i, 3) {
		if (a.at(i).at(2 - i) == 0) {
			ans++;
			if (ans == 3) {
				ans2++;
			}
		}
	}
	ans = 0;
	if (ans2 == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	
	return 0;
}