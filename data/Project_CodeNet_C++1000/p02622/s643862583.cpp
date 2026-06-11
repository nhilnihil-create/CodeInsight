#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
  	int a = 0;
	string s, t;
  	cin >> s >> t;
  	for(int i = 0; i < s.length(); i++)
    {
		a += (s[i] != t[i]);
    }
  
  	cout << a;
	return 0;
}
