#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;cin >>n;
	vector<long long> v;
	for(int i=0;i<n;++i){
		long long a;cin >> a;
		if(a==0){
			cout << 0 << endl;
			return 0;
		}
		v.push_back(a);
	}
	long long out = 1LL;
	for (int j=0; j<v.size();++j){
    if(v[j]<=1000000000000000000/out){
      out *= v[j];
    } else{
      out = -1;
      break;
    }
	}
	cout << out << endl;
	return 0;
}
