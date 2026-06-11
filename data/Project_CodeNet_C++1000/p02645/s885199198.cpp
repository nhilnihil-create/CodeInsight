#include<bits/stdc++.h>
using namespace std;
#define _CRT_SECURE_NO_DEPRECATE
#define ll               long long
#define nl               '\n'                             // NL - sign of new line

#define upc(str, c)      str[c] = toupper(str[c]);         // make single char uppercase
#define lowerc(str, c)   str[c] = tolower(str[c]);         // make single char lowercase

#define ups(str)       	 transform(str.begin(), str.end(), str.begin(), ::toupper); // make entire string uppercase
#define lowers(str)      transform(str.begin(), str.end(), str.begin(), ::tolower); // make entire string lowercase

#define ps(x,y)          fixed << setprecision(y) << x     // usage: t=1.1234; cout << ps(t,4); // it means it will print 4 decimal places.

#define vi               vector <int>                      //create vector of int numbers
#define vs               vector <string>                      //create vector of int numbers
#define eb               emplace_back
#define rev(v)		     reverse(v.begin(), v.end())       // reverse the vector

#define mii			     std::map <int,int>
#define multimii		 std::multimap <int,int>
#define mss			     map <string, string>

#define w(t)             unsigned int t; cin >> t; while(t--)      //  usage: create quickly number of test
mt19937                  rng(chrono::steady_clock::now().time_since_epoch().count());

void c_p_c()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
//==================================6


//==================================
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	c_p_c();
	//--------------------------------


	string s;
	cin >> s;

	cout << s.substr(0, 3);





	return 0;
}