#include <iostream>

using namespace std;

int main()
{
	long long A, B, V, W, T;
	cin >> A >> V;
	cin >> B >> W;
	cin >> T;

	bool Y = true;
	if (A > B) {
		Y = B - T*W >= A - T*V ? true : false;
	} else {
		Y = A + T*V >= B + T*W ? true : false;
	}

	cout << (Y ? "YES" : "NO") << endl;
}
