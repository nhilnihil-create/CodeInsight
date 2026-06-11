#include <string.h>
#include <iostream>
#include <string>

using namespace std;

char str[1000 + 1] = { 0 };

void print(int a, int b)
{
	for (; a <= b; a++)
		cout << str[a];
	cout << endl;
}
void reverse(int a, int b)
{
	char temp = '\0';
	while (a < b) {
		temp = str[a];
		str[a] = str[b];
		str[b] = temp;
		a++;
		b--;
	}
}
void replace(int a, int b, const char *p)
{
	for (int i = 0; i < b - a + 1; i++)
		str[i + a] = p[i];
}

int main()
{
	char command[7 + 1] = { 0 },
		p[1000 + 1] = { 0 };

	int q = 0, a = 0, b = 0;

	cin >> str >> q;
	for (int i = 0; i < q; i++) {
		cin >> command >> a >> b;
		if (command[0] == 'p') {
			print(a, b);
		}
		else if (command[2] =='v') {
			reverse(a, b);
		}
		else {
			cin >> p;
			replace(a, b, p);
		}
	}
	return 0;
}