#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	string s, t; cin >> s >> t;
	int S; S = s.size();
	string T;T= t.erase(S);
	if (s == T) { cout << "Yes" << endl; }
	else { cout << "No" << endl; }
}
