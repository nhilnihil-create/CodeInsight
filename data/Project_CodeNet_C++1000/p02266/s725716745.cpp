#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int solve(){
	stack<long> s;
	vector<pair<long, long> > v;
	char ch;
	long j, sub, sum = 0;

	for (long i = 0; cin >> ch; i++){
		if (ch == '\\') s.push(i);
		else if (ch == '/' && !s.empty()){
			j = s.top(); 
			s.pop();
			sub = i - j;
			sum += sub;
			while (!v.empty() && v.back().first > j){
				sub += v.back().second;
				v.pop_back();
			}
			v.push_back(make_pair(j, sub));
		}
	}
	cout << sum << endl << v.size();
	for (int i = 0; i < v.size(); i++) cout << " " << v[i].second;
	cout << endl;
}

signed main(){
	solve();
}