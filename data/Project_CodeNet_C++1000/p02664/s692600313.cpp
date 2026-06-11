#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
	string t;

	cin >> t;

	for(int i=0; i<t.size(); i++){
		if(t[i] == '?'){
			t[i] = 'D';
		}
	}

	cout << t << endl;
}
