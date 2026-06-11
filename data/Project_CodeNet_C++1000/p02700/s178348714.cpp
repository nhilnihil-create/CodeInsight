#include <iostream>
using namespace std;
int main()
{
	int th, ts, ah, as;
	cin >> th >> ts >> ah >> as;
	while (true)
	{
		ah = (ah - ts);
		th = (th - as);
		if (ah <= 0)
		{
			cout << "Yes";
			break;
		}
		else if (th <= 0) {
			cout << "No";
			break;
		}
	}
}