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
	int x, y;
	cin >> x >> y;
	if (y % 2 != 0||x*4<y||x*2>y) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
	
	return 0;
}//どうして・・・(´･_･`)
