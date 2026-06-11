#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	char c[201],c2[101],c3[101];
	cin >> c >> c3;
	strcpy(c2,c);
	strcat(c,c2);

	if(strstr(c,c3) == NULL) cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}