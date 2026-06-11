#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

int mod = 998244353;

#define swap(x,y){ long long temp = x; x = y; y = temp;}


int main()
{
	 string s;
	 cin >> s;
	 for(int i=0;i<s.length();i++)
	 {
		 	if(s[i]=='?')
			{
				s[i] = 'D';
			}
	 }

	 cout << s << endl;

}
