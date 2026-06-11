#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)


int main()
{
	vector<vector<int> > A(3, vector<int>(3));
	int N;
	
	rep(i, 3) {
		rep(j, 3) {
			cin >> A.at(i).at(j);
		}
	}
	cin >> N;
	vector<int> B(N);
	int S;
	vector<vector<bool> > buf(3, vector<bool>(3,false));
	rep(k, N) {
		cin >> S;
		rep(i, 3) {
			rep(j, 3) {
				if (A.at(i).at(j) == S) {
					buf.at(i).at(j) = true;
				}
			}
		}
	}
	rep(i, 3) {
		if (buf.at(i).at(0) && buf.at(i).at(1) && buf.at(i).at(2))
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	rep(i, 3) {
		if (buf.at(0).at(i)&& buf.at(1).at(i)&& buf.at(2).at(i))
		{
			cout << "Yes" << endl;
			return 0;
		}
	}

	if (buf.at(0).at(0)&& buf.at(1).at(1)&& buf.at(2).at(2))
	{
		cout << "Yes" << endl;
		return 0;
	}

	if (buf.at(0).at(2) && buf.at(1).at(1) && buf.at(2).at(0)) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
}