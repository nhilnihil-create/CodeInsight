#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
int main(){
	
	string s; cin>>s;
	int n = s.size();
	vector<vector<ll>> sum(n+1,vector<ll>(13));
	int k{};
	sum.at(0).at(0) = 1;
	for(auto i:s){
		k++;
		if('0'<=i && i<='9'){
			for(int j=0; j<13; j++){
				( sum.at(k).at((j*10+i-'0')%13) += sum.at(k-1).at(j) ) %=MOD;
			}
			
		}
		else {
			for(int l=0; l<10; l++){
				for(int j=0; j<13; j++){
					( sum.at(k).at((j*10+l)%13) += sum.at(k-1).at(j) ) %=MOD;
				}
			}
		}
	}
	cout << sum.at(n).at(5) << endl;
	
}
