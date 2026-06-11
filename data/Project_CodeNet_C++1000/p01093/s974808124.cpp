#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> ans;

int main(){
	while(1){
		int n;
		cin >> n;
		if(n == 0) break;
		int a[1000];
		for(int i = 0;i < n;i++){
			cin >> a[i];
		}
		sort(a,a+n);
		int minn = 1e9;
		for(int i = 0;i < n-1;i++){
			int dif = abs(a[i] - a[i+1]);
			minn = min(minn,dif);
		}
		ans.push_back(minn);
	}
	for(int i = 0;i < ans.size();i++)cout << ans[i] << endl;
	return 0;
}