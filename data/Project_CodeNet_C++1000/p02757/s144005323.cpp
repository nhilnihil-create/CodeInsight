#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	//cin.exceptions(cin.failbit);
    
    long long n,p;
    cin >> n >> p;  
   	string s;
   	cin >> s;
   	long long res =0;
   	if (p==2 || p == 5)
   	{
   		for (int i =0;i<s.length();i++)
   		{
   			if ((s[i]-'0')%p==0) res+= i+1;
   		}
   		cout << res << '\n';
   		return 0;
   	}
   	map<long long,long long> mp;
   	mp[0] = 1;
   	long long powten = 1;
   	long long t = 0;
   	for (long long i=s.length()-1;i>=0;i--)
   	{
   		t = ((long long)(s[i]-'0')*powten%p + t) % p;
   		powten = powten*10%p;
   		res += mp[t];
   		mp[t]++;
   	}
   	cout << res << '\n';	
	return 0;
}
	