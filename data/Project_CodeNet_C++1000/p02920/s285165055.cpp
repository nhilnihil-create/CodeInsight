#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(V) V.begin(),V.end()
#define FINISH cout<<"No"<<endl;return 0;

int main(){
	int N;
	cin >> N;
	int a = 1;
	for (int i = 0;i < N;i++)a *= 2;
	vector<int> X(a);
	multiset<int> S;
	priority_queue<int> Q, R;
	for (int i = 0;i < a;i++) {
		cin >> X[i];
		S.insert(X[i]);
	}
	auto it = S.end();it--;
	Q.push(*it);
	S.erase(it);

	for (int i = 0;i < N;i++) {
		while (!Q.empty()) {
			a = Q.top();
			Q.pop();
			it = S.lower_bound(a);
			if (it == S.begin()) { FINISH; }
			it--;
			R.push(a);
			R.push(*it);
			S.erase(it);
		}
		swap(Q, R);
	}
	cout << "Yes" << endl;
}