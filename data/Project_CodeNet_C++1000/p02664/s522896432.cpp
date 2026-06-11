#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N = 1e5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s; cin >> s;
	for(int i = 0; i < s.length(); i++)
		if(s[i]=='?')
			s[i] = 'D';
	cout<<s<<endl;

	cout<<flush;
	return 0;
}