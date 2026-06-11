#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_comparing_strings(void) {
	string a, b;
	cin >> a >> b;
	
	string ab="", ba="";
	for (int i = 0; i < stoi(b); i++) ab += a;
	for (int i = 0; i < stoi(a); i++) ba += b;

	if (ab < ba) cout << ab << endl;
	else         cout << ba << endl;

}

int main()
{
    b_comparing_strings();

    return 0;
}