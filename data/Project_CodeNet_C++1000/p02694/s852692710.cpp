#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


void func()
{
	int64_t X;
	cin >> X;

	int64_t ans = 0;
	int64_t gankin = 100;
	while (gankin < X)
	{
		gankin += gankin/100;
		ans++;
	}
	cout << ans << endl;

}

int main() {

//	while (1)
		func();
	return 0;
}
