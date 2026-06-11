#include <iostream>
#include <vector>
using namespace std;

int main() {
	int a,b,m; cin>> a >> b>>m;
	vector<int> va(a),vb(b);
	int min_a = 1000000;
	int min_b = 1000000;
	for(int i=0; i<a;++i){
		 cin >>va[i];
		 min_a = min(min_a, va[i]);
	}
	for(int i=0; i<b;++i) 
	{
		cin >>vb[i];
		min_b = min(min_b, vb[i]);
	}
	int out = min_a + min_b;
	for(int j=0;j<m;++j){
		int x,y,c;cin >> x >> y>>c;
		out = min(out, va[x-1]+vb[y-1]-c);
	}
	cout << out << endl;
	return 0;
}