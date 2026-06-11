#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
int n,k;

bool check(int d){
	vector<int> v;

	int sm = 0;
	for(int i = 0; i < (int)arr.size(); i++){
		int r = arr[i]%d;
		if(r!=0) v.push_back(r);
		sm+=r;
	}

	if(v.size() == 0) return true;
	if(sm%d!=0) return false;
	sort(v.begin(),v.end());
	deque<int> dq;
	for(int i: v) dq.push_back(i);
	int res = k;
	while(dq.size()){
		if(dq.size() == 1) return false;
		int s = dq.front();
		int q = dq.back();
		int mn = min(s,d-q);
		dq.front() -= mn;
		if(dq.front() == 0) dq.pop_front();
		dq.back()+=mn;
		if(dq.back() == d) dq.pop_back();
		res-=mn;
		if(res<0) return false;
	}
	return true;
}

int main(){
	cin>>n>>k;
	
	int res = 1;
	int sm = 0;
	for(int i = 0; i < n; i++){
		int x;cin>>x;
		sm+=x;
		arr.push_back(x);
	}

	for(int i = 1; i*i<=sm; i++){
		if(check(i)) res = max(res,i);
		if(check(sm/i)) res = max(res,sm/i);
	}
	cout<<res;
}