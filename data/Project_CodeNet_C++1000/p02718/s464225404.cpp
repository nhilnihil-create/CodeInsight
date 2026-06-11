#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n,m;cin>>n>>m;
	vector<int> v(n);
	int tot=0;
	for(int i=0;i<n;++i){
		cin >> v[i];
		tot += v[i];
	}
	sort(v.begin(),v.end(),greater<int>());
	bool isok = true;
	for(int j=0;j<m;++j){
		if(4*m*v[j]<tot) {
			isok =false;
		}
	}
	if(isok){
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}