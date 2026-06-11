#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string str;
	cin >> str;
	string str2 = str;

	int q;
	cin >> q;

	int start, end;
	string command;

	for (int i = 0; i < q; i++) {
		cin >> command;
		if (command == "print") {
			cin >> start >> end;
			for (int i = start; i <= end; i++) {
				cout << str[i];
			}
			cout << "\n";
		}
		else if (command == "reverse") {
			cin >> start >> end;
			int end2 = end;
			for (int j = start; j <= end; j++) {
				str[j] = str2[end2--];
			}
			str2 = str;
		}
		else if (command == "replace") {
			string rstr;
			cin >> start >> end >> rstr;
			int ri = 0;
			for (int j = start; j <= end; j++) {
				str[j] = rstr[ri++];
			}
			str2 = str;
		}
	}
}