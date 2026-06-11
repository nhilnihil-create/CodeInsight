#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string stc;
	//stc = "Hello, World.";
	vector<long> fl(26, 0);
	char alp[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	while (cin >> stc){
		for (long i = 0; i < stc.size(); i++){
			if (isupper(stc[i])) stc[i] = tolower(stc[i]);
			long cd;
			cd = (char)stc[i] - (long)'a';
			//cout << cd << endl;
			if (cd >= 0 && cd <= 25) fl[cd]++;
		}
	}
	for (long i = 0; i < 26; i++){
		cout << alp[i] << " : " << fl[i] << endl;
	}
	return 0;
}