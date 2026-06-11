#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long int ll;

int main(){
	int x,y,a,b,c;
	cin >> x >> y >> a >> b >> c;
	
	vector<int> p(a),q(b),r(c);
	
	for(int i=0;i<a;++i){
		cin >> p[i];
	}
	for(int i=0;i<b;++i){
		cin >> q[i];
	}
	for(int i=0;i<c;++i){
		cin >> r[i];
	}
	sort(p.begin(),p.end(),greater<int>());
	sort(q.begin(),q.end(),greater<int>());
	sort(r.begin(),r.end(),greater<int>());
	
	vector<int> sol;
	for(int i=0;i<min(a,x);++i){
		sol.push_back(p[i]);
	}
	for(int i=0;i<min(b,y);++i){
		sol.push_back(q[i]);
	}
	for(int i=0;i<c;++i){
		sol.push_back(r[i]);
	}
	
	
	
	unsigned long long int res = 0;
	sort(sol.begin(),sol.end(),greater<int>());
	for(int i=0;i<x+y;++i){
		res += sol[i];
	}
	cout << res <<endl;
	
	return 0;
}
