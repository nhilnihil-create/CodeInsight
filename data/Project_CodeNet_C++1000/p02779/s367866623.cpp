#include <bits/stdc++.h>
using namespace std;

void solve(){
	set < int > s;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int p;
		cin >> p;
		s.insert(p);
	}
	if(s.size() == n){
		cout << "YES" << "\n";
	}
	else{
		cout << "NO" << "\n";
	}
	
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();

}