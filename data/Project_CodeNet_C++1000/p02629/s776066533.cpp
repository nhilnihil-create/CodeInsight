#include<bits/stdc++.h>
using namespace std;
long long n;
stack<char>s;
int main()
{
	cin>>n;
	while(n)
	{
		n--;
		long long shang=n/26;
		long long yu=n%26;
		n=shang;
		s.push((char)('a'+yu));
	}
	while(!s.empty())
	{
		cout<<s.top();s.pop();
	}
}