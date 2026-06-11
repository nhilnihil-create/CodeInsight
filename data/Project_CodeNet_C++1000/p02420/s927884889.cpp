#include<iostream>
#include<string>
using namespace std;

int main(){
	int n, h;
	
	while(1){
		string cards, subcards;
		cin >> cards;

		if (cards == "-") break;
		cin >> n;

		for (int i = 0; i < n; i++){
			cin >> h;
			subcards = cards.substr(0, h);
			cards = cards.erase(0, h);
			cards = cards + subcards;
		}
		cout << cards << "\n";
	}

	return 0;
}
