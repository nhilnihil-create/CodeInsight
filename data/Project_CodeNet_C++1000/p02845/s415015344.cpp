#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
int main(){
	
	int n; cin>>n;
	vector<int> a(n);
	for(auto &i:a) cin>>i;
	vector<int> b(3,-1);
	ll sum{1};
	for(int i=0; i<n; i++){
		bool flg{};
		int cnt{};
		for(int j=2; j>=0; j--){
			if(a.at(i)==b.at(j)+1){
				cnt++;
				if(!flg){
					flg=1;
					b.at(j)++;
				}
			}
		}
		(sum *= cnt) %= MOD;
	}
	cout << sum << endl;
	
}
