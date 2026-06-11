#include<bits/stdc++.h>
using namespace std;

long long X, Y, A, B, C;

int main(){
	cin >> X >> Y >> A >> B >> C;

	priority_queue<long long, vector<long long>, greater<long long> > RED;
	priority_queue<long long, vector<long long>, greater<long long> > GREEN;
	priority_queue<long long> NO;

	for(long long i = 0; i < A; i++) {
		long long tmp;
		cin >> tmp;
		RED.push(tmp);
	}

	for(long long i = 0; i < B; i++) {
		long long tmp;
		cin >> tmp;
		GREEN.push(tmp);
	}

	for(long long i = 0; i < C; i++) {
		long long tmp;
		cin >> tmp;
		NO.push(tmp);
	}

	while(RED.size() > X) {
		RED.pop();
	}

	while(GREEN.size() > Y) {
		GREEN.pop();
	}

	while(!NO.empty()) {
		if(RED.top() < GREEN.top()) {
			//REDに変更
			if(RED.top() < NO.top()) {
				RED.pop();
				RED.push(NO.top());
				NO.pop();
			} else {
				break;
			}
		} else {
			//GREENに変更
			if(GREEN.top() < NO.top()) {
				GREEN.pop();
				GREEN.push(NO.top());
				NO.pop();
			} else {
				break;
			}
		}
	}

	long long ans = 0;
	while(!RED.empty()) {
		ans += RED.top();
		RED.pop();
	}

	while(!GREEN.empty()) {
		ans += GREEN.top();
		GREEN.pop();
	}
	cout << ans << endl;



}

