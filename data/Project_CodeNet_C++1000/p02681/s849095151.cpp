#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	string t;
	cin >> s;
	cin >> t;
	bool bad = false;

	int size = s.size();
//	cout << size;

	for(int i = 0; i < size; i++){
		if(s[i] != t[i]){
			bad = true;
//			cout << i;
			break;
		}
	}

	if(bad)
		cout << "No";
	else
		cout << "Yes";
}