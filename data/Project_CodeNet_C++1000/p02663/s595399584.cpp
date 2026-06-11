#include<iostream>
#include<algorithm>
 
using namespace std;
int main()
{
  	int h1, m1, h2, m2, k, ans;
  	cin >>  h1 >> m1 >> h2 >> m2 >> k;
    ans = (h2 * 60 + m2) - (h1 * 60 + m1) - k;
	if (ans < 0) ans = 0;
	cout << ans << endl;
	return 0;
}