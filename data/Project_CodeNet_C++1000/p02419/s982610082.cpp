#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	string text;
	int count = 0;

	cin >> word;
	while (cin >> text, text != "END_OF_TEXT"){
		for (int i = 0; i < text.length(); i++){
			if (isupper(text[i])){
				text[i] = tolower(text[i]);
			}
		}
		if (text == word)
			count++;
	}

	cout << count << endl;

	return 0;
}