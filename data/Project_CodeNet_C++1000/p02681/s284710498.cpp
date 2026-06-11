#include <iostream>
#include <cstdio>
using namespace std;

string a, b;
int main()
{
	cin >> a;
	cin >> b;
	b.pop_back();
	if (a == b) cout << "Yes";
	else cout << "No";
    return 0;
}
