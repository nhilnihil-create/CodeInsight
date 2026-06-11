#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	string l; cin>>l;
	vector<vector<ll>> dp(l.size(),vector<ll>(2));
	dp.at(0).at(0) = 2;
	dp.at(0).at(1) = 1;
	for(int i=1; i<l.size(); i++){
		if(l.at(i)=='0'){
			(dp.at(i).at(0)+=dp.at(i-1).at(0))%=MOD;
			(dp.at(i).at(1)+=dp.at(i-1).at(1)*3)%=MOD;
		}
		if(l.at(i)=='1'){
			(dp.at(i).at(0)+=dp.at(i-1).at(0)*2)%=MOD;
			(dp.at(i).at(1)+=dp.at(i-1).at(1)*3)%=MOD;
			(dp.at(i).at(1)+=dp.at(i-1).at(0))%=MOD;
		}
	}
	cout << (dp.back().at(0)+dp.back().at(1))%MOD << endl;
	
}

