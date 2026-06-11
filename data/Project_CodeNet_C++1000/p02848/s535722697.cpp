#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
	int n;
	string s;
	cin >> n >> s;
	string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int num = s.size();
	for(int x = 0  ;x < num; x++ )
	{
		
		for(int y=0 ; y < 26 ; y++ )
		{
			if (s[x]==b[y])
			{
				cout << a[y + n];				
			}
		}
	}

	cout << "\n";


	return 0;
}