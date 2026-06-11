#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
using ll = long long;

int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin >> a.at(i);
	}
	set<ll> a2(a.begin(),a.end());
	if(a2.size() == n){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
