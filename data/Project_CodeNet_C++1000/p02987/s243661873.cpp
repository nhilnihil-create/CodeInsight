#include <iostream>
using namespace std;

bool isAccepted = 1;
char word[4];
string input;
int freq[30] = {};

int main() {
	
	for(int i = 0 ; i < 4 ; ++i)	cin >> word[i];
	
	for(int i = 0 ; i < 4 ; ++i)	freq[word[i] - 'A']++;
	
	for(int i = 0 ; i < 30 ; ++i)
		if(freq[i] == 1 || freq[i] > 2)
			isAccepted = 0;
			
	if(isAccepted)	cout << "Yes";
	else			cout << "No";
	
	return 0;
}