#include<iostream>
#include<string>
#include<algorithm>
#define LL long long
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

bool isPalindrome(string s)
{
	string tmp1=s, tmp2=s;
	reverse(tmp1.begin(), tmp1.end());
	if(tmp1==tmp2) return true; else return false;
}

int main()
{
	FIO;
	bool x=false, y=false, z=false;
	string s; cin>>s;
	int n=s.size();
	x=isPalindrome(s);
	string s1=s.substr(0, (n-1)/2);
	y=isPalindrome(s1);
	string s2=s.substr((n+3)/2-1, n);
	z=isPalindrome(s2);
	if(x&&y&&z) cout<<"Yes\n"; else cout<<"No\n";
}