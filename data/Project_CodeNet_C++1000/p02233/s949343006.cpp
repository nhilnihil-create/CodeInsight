#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	if( N >= 2){
		vector<unsigned> f;
		f.push_back(1);
		f.push_back(1);
		for(int i = 2; i <= N; i++){
			int temp = f.at(i-1) + f.at(i-2);
			f.push_back(temp);
		}
		cout << f.at(N) << endl;;
	}else{
		cout << 1 << endl;
	}
	
	return 0;
}