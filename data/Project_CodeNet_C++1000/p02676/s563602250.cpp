#include <iostream>
#include<string>
using namespace std;
int main(){
	int k;
	string s;
	cin >> k >> s;
	int n = s.size() - k ;
	if (k < s.size()) {
		for (int i = 0; i<n; i++)
			s.pop_back();
		cout << s << "...";
	}
	else
		cout << s;
}