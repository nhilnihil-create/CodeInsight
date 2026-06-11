#include <iostream>

#define REP(loop, n) for(int i = (loop) ; i < n ; ++i)

using namespace std;

int main(void)
{
	string S;
	cin >> S;

	cout << S.substr(0, 3) << endl;

	rewind(stdin);
	char c = getchar();
	return 0;
}
