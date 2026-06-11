#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,ans,x;
	vector<int> vec;
	while(1){
		cin >> n;
		if(n == 0)break;
		ans = 10000000;
		vec.clear();
		for(int i = 0;i < n;i++){
			cin >> x;
			vec.push_back(x);
		}
		sort(vec.begin(),vec.end());
		for(int i = 1;i < n;i++){
			ans = min(ans,vec[i] - vec[i-1]);
		}
		cout << ans <<endl;
	}
	return 0;
}