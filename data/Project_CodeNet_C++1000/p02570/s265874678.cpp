#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	double d, t, s;
  	cin >> d >> t >> s;
  	if(d/s <= t)
      	cout << "Yes";
  	else
      	cout << "No";

	return 0;
}
