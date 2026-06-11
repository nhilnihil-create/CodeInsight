#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)

using namespace std;

long long N, D, A;

vector<pair<long long, long long> > XH;
queue<pair<long long, long long> > imo;


int main(){
	cin >> N >> D >> A;
	rep(i, N) {
		long long x, h;
		cin >> x >> h;
		XH.push_back(make_pair(x, h));
	}

	sort(XH.begin(), XH.end());


	long long ans = 0;
	long long cur = 0;
	rep(i, N) {
		long long x = XH[i].first;
		long long h = XH[i].second;
		//cout << "x = " << x << " h = " << h << " cur = " << cur << endl;

		while(!imo.empty() && imo.front().first <= x) {
			cur -= imo.front().second;
			imo.pop();
		}
		//cout << " cur = " << cur << endl;

		if(cur < h) {
			long long cou;
			if((h-cur)%A == 0) {
				cou = (h-cur)/A;
			} else {
				cou = (h-cur)/A + 1;
			}
			//cout << "i = " << i << " plus " << cou << " min " << i + 2 * D + 1 << " dmg = " << cou * A << endl;
			imo.push(make_pair(x + 2 * D + 1, cou * A));
			ans += cou;
			cur += cou * A;
		}
	}
	cout << ans << endl;
}
