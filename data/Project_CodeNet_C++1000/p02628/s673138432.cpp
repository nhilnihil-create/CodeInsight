#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
	int n,k;cin >> n>>k;
	vector<int> v(n);
	for (int i=0;i<n;++i){
		cin >>v[i];
	}
	sort(v.begin(),v.end());
	int out =0;
	for (int j=0;j<k;++j){
		out +=v[j];
	}
	cout << out << endl;
	return 0;
}