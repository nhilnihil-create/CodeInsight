#include<bits/stdc++.h>
using namespace std;

long long K;
vector<long long> nums;

int main(){
	cin >> K;

	queue<long long> q;
	queue<long long> qnext;
	for(long long i = 1; i < 10; i++) {
		nums.push_back(i);
		q.push(i);
	}


	while(1) {
		while(!q.empty()) {
			long long num = q.front();
			q.pop();

			if(num%10 == 0) {
				nums.push_back(num * 10 + 0);
				nums.push_back(num * 10 + 1);
				qnext.push(num * 10 + 0);
				qnext.push(num * 10 + 1);
			} else if (num%10 == 9) {
				nums.push_back(num * 10 + 8);
				nums.push_back(num * 10 + 9);
				qnext.push(num * 10 + 8);
				qnext.push(num * 10 + 9);
			} else {
				nums.push_back(num * 10 + num%10 - 1);
				nums.push_back(num * 10 + num%10);
				nums.push_back(num * 10 + num%10 + 1);
				qnext.push(num * 10 + num%10 - 1);
				qnext.push(num * 10 + num%10);
				qnext.push(num * 10 + num%10 + 1);
			}
		}
		swap(q, qnext);

		if(nums.size() > K) {
			sort(nums.begin(), nums.end());
			cout << nums[K-1] << endl;
			return 0;
		}
	}
}