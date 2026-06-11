#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

multiset<pair<long long int, pair<long long int ,long long int>>> P, M;

int N;
long long int x[200005], y[200005];

long long int INF = 999999999999999;

int main(void) {

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x[i] >> y[i];
		P.insert(make_pair(x[i] + y[i],make_pair(x[i],y[i])));
		M.insert(make_pair(x[i] - y[i],make_pair(x[i],y[i])));
	}

	long long int ans = 0;
	long long int tmp_x,tmp_y, tmp_p, tmp_m;

	pair<long long int, pair<long long int, long long int>> q, r;

	for (int i = 1; i <= N; i++) {
		q.first = x[i] + y[i]; q.second.first = x[i]; q.second.second = y[i];
		auto it = P.find(q); P.erase(it);

	//cout << q.first << " " << q.second.first << " " << q.second.second << endl;

		r.first = x[i] - y[i]; r.second.first = x[i]; r.second.second = y[i];
		auto itr = M.find(r); M.erase(itr);


		//-----
		it = P.end(); it--;
		tmp_p = (*it).first;  tmp_x = (*it).second.first; tmp_y = (*it).second.second;
		ans = max(ans, abs(tmp_x - x[i]) + abs(tmp_y - y[i]));
        //----
		it = P.upper_bound(make_pair(tmp_p, make_pair(INF, INF)));
		it--;
		tmp_p = (*it).first;  tmp_x = (*it).second.first; tmp_y = (*it).second.second;
		ans = max(ans, abs(tmp_x - x[i]) + abs(tmp_y - y[i]));
		//-----

		itr = M.end(); itr--;
		tmp_m = (*itr).first; tmp_x = (*itr).second.first; tmp_y = (*itr).second.second;
		ans = max(ans, abs(tmp_x - x[i]) + abs(tmp_y - y[i]));

		//cout << tmp_m << " " << tmp_x << " " << tmp_y << endl;
		
		//-----
		itr = M.upper_bound(make_pair(tmp_m, make_pair(INF, INF))); itr--;
		tmp_m = (*itr).first; tmp_x = (*itr).second.first; tmp_y = (*itr).second.second;
		ans = max(ans, abs(tmp_x - x[i]) + abs(tmp_y - y[i]));
		

		P.insert(q);
		M.insert(r);
		
	}

	cout << ans << endl;

	return 0;
}
