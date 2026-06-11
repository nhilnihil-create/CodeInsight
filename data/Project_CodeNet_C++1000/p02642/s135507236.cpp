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

	sort(num.begin(), num.end());

	vector<bool> isPrime(SIZE, true);
	vector<pib> ans;

	for(int i=0;i<n;i++){
		bool check = true;
		int sqrtn = (int)sqrt(num[i]);
		for(int j=1;j<=sqrtn && check;j++){
			if(!(num[i] % j)){
				if(!isPrime[j]) check = false;
				if(!isPrime[num[i] / j]){
					check = false;
					if(ans.back().first == num[i]) ans.back().second = true;
				}
			}
		}
		if(check){
			ans.push_back(make_pair(num[i], false));
		}
		isPrime[num[i]] = false;
	}

	int val = 0;
	for(int i=0;i<ans.size();i++){
		if(!ans[i].second) val++;
	}
	cout<<val;
}