#include <bits/stdc++.h>
using namespace std;


int main() {
	long long k;
	cin >> k;
	vector<long long> a;
	queue<long long> que;
	long long count=0;
	for(long long i=1;i<=9;i++){
		a.push_back(i);
		que.push(i);
		count++;
	}
	while(count<=k){
		long long v=que.front();
		que.pop();
		if(v%10!=0){
			a.push_back(v*10+v%10-1);
		    que.push(v*10+v%10-1);
		    count++;
		}
		a.push_back(v*10+v%10);
	    que.push(v*10+v%10);
		count++;
		if(v%10!=9){
			a.push_back(v*10+v%10+1);
		    que.push(v*10+v%10+1);
		    count++;
		}
	}
	sort(a.begin(),a.end());
	cout << a[k-1] << endl;
}
