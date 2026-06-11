// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

long long d[N], c[N];
pair<int,int> co[10];

void Push(stack<int>&st, int now) {
	st.push(now % 10);
	if(now >= 10) st.push(now / 10);
}


pair<int,int> calculate(int num) {
	int ops = 0, used = 0;
	ops++;
	used++;
	stack<int> st;
	Push(st, num + num);
	while(!(st.size() == 1 && st.top() == num)) {
		ops++;
		if(st.size() == 2) {
			int take1 = st.top();
			st.pop();
			int take2 = st.top();
			st.pop();
			Push(st, take1 + take2);
		}
		else {
			used++;
			int now = st.top();
			st.pop();
			Push(st, now + num);
		}
	}
	return make_pair(ops, used);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<10;i++) co[i]=calculate(i);
	long long answer = 0;
	for(int i=0;i<n;i++) {
		cin >> d[i] >> c[i];
		if(c[i] >= 20){
			long long step = co[d[i]].second;
			long long ret = co[d[i]].first;
			answer += ((c[i]-20)/step)*ret;
			c[i] -= ((c[i]-20)/step)*step;
		}
	}
	vector<int> v;
	for(int i=0;i<n;i++) {
		for(int j=0;j<c[i];j++)v.push_back(d[i]);
	}
	int ind = 1;
	stack<int> st;
	Push(st, v[0]);
	while(st.size()>=2 || ind < v.size()) {
		if(st.size() >= 2) {
			answer++;
			int take1 = st.top();
			st.pop();
			int take2 = st.top();
			st.pop();
			Push(st, take1 + take2);
		}
		else if(st.size() == 1) {
			answer++;
			int take1 = st.top();
			st.pop();
			Push(st, take1 + v[ind++]);
		}
	}
	cout << answer;
	return 0;
}
