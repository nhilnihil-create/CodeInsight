#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin.ignore(256, '\n');

	string altar; cin >> altar;

	int ops{ 0 };

	for (int white_start = 0, red_start = altar.size() - 1; true; ++ops)
	{
		int i_red = red_start;
		for (; i_red > white_start + 1 && altar[i_red] != 'R'; --i_red);

		int i_white = white_start;
		for (; i_white < i_red - 1 && altar[i_white] != 'W'; ++i_white);

		if (altar[i_red] != 'R' || altar[i_white] != 'W') { break; }

		white_start = i_white + 1;
		red_start = i_red - 1;
	}
	
	cout << ops << '\n';
}