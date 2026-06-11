#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
	int n;
	while(cin >> n,n){
		vector<int> data(n);
		rep(i,n)cin >> data[i];
		int ret = 0;
		rep(i,n)ret = min(ret,data[i]);
		rep(i,n){
			int sum = 0;
			for(int j=i;j<n;j++){
				sum += data[j];
				ret = max(sum,ret);
			}
		}
		cout << ret << endl;
	}
}