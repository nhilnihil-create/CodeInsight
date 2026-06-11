#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main()
{
	int x;
	rep(i, 5) {
		cin >> x;
		if (x == 0) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	return 0;
}//どうして・・・(´･_･`)
