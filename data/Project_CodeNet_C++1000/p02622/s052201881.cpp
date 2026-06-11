#include <iostream>

using namespace std;

int main(){
	string s;
	string v;
	int count = 0;
	cin >> s >> v;
	for(int i = 0; i < s.length(); i++){
		if (s[i] != v[i]){
			count++;
		}
	}	
	cout << count << endl;
	return 0;
}
