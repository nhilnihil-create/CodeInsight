#include<iostream>
#include<string>
#define ll long long
using namespace std;
int main()
{
	//string  dog;
	//string pig;
	//getline(cin, dog);
	//getline(cin, pig);
	//string cat = pig.substr(0, pig.size() - 1);
	////cout << cat;
	//if (dog == cat)
	//	cout << "Yes";
	//else
	//	cout << "No";
	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	ll ans = 0;
	while (k >0)
	{
		if (a > 0) {
			a -= 1;
			ans += 1;
			k -= 1;
			//cout << "a" << endl;
		}
		else if (b > 0) 
		{
			b -= 1;
			k -= 1;
			//cout << "b" << endl;
		}
		else if (c > 0)
		{
			c -= 1;
			ans -= 1;
			k -= 1;
			//cout << "c" << endl;
		}
		
	}
	cout << ans;
	
    return 0;
}

