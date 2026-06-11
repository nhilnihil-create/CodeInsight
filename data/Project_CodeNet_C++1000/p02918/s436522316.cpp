#include<bits/stdc++.h>
using namespace std;
using ll = long long; 

int main(){
	int n,k;
	string s;
	cin >> n >> k >>s;
	int hps{};
	for(int i=0; i<n; i++){
		if(s.at(i)=='L'){
			if(i-1>=0&&s.at(i-1)=='L') hps++;
		}
		if(s.at(i)=='R'){
			if(i+1<n&&s.at(i+1)=='R') hps++;
		}
	}
	cout << min(n-1,hps+k*2) << endl;
	
}