#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int x; cin>>x;
	if(x>2000) {
		cout << 1 << endl;
		return 0;
	}
	else{
		int a=100, b=105;
		for(int i=1; i<=20; i++){
			if(a*i<=x&&x<=b*i){
				cout << 1 << endl;
				return 0;
			}
		}
	}
	cout << 0 << endl;
	
}
