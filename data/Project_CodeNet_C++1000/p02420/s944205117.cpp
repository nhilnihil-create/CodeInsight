#include <iostream>
#include <string>

using namespace std;

int main(){
	while(true){
		int m, h;
		string cards;
		cin >> cards;
		if(cards == "-") break;
		cin >> m;
		while(m){
			cin >> h;
			string substr = cards.substr(0, h);
			cards.erase(0, h);
			cards += substr;
			m--;
		}
		cout << cards << endl;
	}

	return 0;
}