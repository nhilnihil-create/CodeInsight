#include <iostream>

using namespace std;

string s;

int main(){
	cin >> s;
	if((int)s.size() % 2 != 0){
		cout << "No\n"; return 0;
	}
	for(int i = 0;i < (int)s.size();i++){
		if(i % 2 == 0 && s[i] != 'h'){
			cout << "No\n"; return 0;			
		}
		if(i % 2 == 1 && s[i] != 'i'){
			cout << "No\n"; return 0;			
		}
	}
	cout << "Yes\n";
}