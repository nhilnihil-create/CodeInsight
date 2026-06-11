#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;cin>>n;
	vector<pair<string,int>> vp(n);
	for(int i=0;i<n;++i){
		string s;
		int t;
		cin >>s>>t;
		vp[n-1-i] = make_pair(s,t);
	}
	string x;cin>>x;
	int out = 0;
	for(int i=0;i<n;++i){
		if(vp[i].first!=x){
			out += vp[i].second;
		} else {
			break;
		}
	}
	cout << out << endl;
	return 0;
}