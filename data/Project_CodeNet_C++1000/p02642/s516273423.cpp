#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define SIZE 1000001
#define pib pair<int,bool>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; cin>>n;
	vector<int> num(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	if(n == 1){
		cout<<1;
		return 0;
	}

	sort(num.begin(), num.end());
	if(num[0] == 1){
		cout<<(num[0] == num[1] ? 0 : 1);
		return 0;
	}
	vector<bool> isPrime(SIZE, true);
	vector<pib> ans;

	for(int i=0;i<n;i++){
		bool curCheck = true;
		int sqrtn = (int)sqrt(num[i]);
		for(int j=2;j<=sqrtn;j++){
			if(!(num[i] % j)){
				if(!isPrime[j] || !isPrime[num[i] / j]){
					curCheck = false;
					break;
				}
			}
		}
		if(curCheck){
			if(ans.size() && ans.back().first == num[i]){
				ans.back().second = true;
			}else{
				ans.push_back(make_pair(num[i], false));
			}
		}
		isPrime[num[i]] = false;
	}
	
	int val = 0;
	for(int i=0;i<ans.size();i++){
		if(!ans[i].second) val++;
	}
	cout<<val;
}