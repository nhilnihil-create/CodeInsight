#include <bits/stdc++.h>
using namespace std;
int main(){
	set <string> s;
	int n;
	string tmp;
	cin >> n;
	while(n--){
		cin >> tmp;
		s.insert(tmp);
	}
	cout << (int)s.size() << endl;
}
