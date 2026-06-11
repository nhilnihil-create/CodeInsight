#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	int counts = 0;
	for(int i = 1; i<10; i++){
	for(int j = 1; j<10; j++){
		if(n%i == 0 && n/i ==j) counts++;
	}
	}
	if(counts == 0) cout << "No" << endl;
	else cout << "Yes" << endl;
} 