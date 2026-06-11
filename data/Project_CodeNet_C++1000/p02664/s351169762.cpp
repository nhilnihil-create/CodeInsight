# include <cstdio>
# include <iostream>
# include <vector>
# include <map>
# include <set> 
# include <algorithm> 
# include <string>
# include <cstring>
# include <queue> 
# include <stack> 
# include <cstdlib> 

using namespace std ; 

int main()
{
	string s ; 
	cin >> s; 
	int len = s.length(); 
	for(int i = 0 ; i < len; )
	{
		if(s[i]=='P' || s[i]=='D'){ 
			++i;
			continue ; 
		}
		if(i > 0)
		{
			if(s[i-1]=='P'){
				s[i] = 'D' ; 
				++i;
				continue;
			}
		}
		if(i<len-1)
		{
			if(s[i+1]=='D'){
				s[i] = 'P' ; 
				++i ; 
				continue ; 
			}
			else if(s[i+1]=='?')
			{
				s[i]='P';
				s[i+1]='D'; 
				i+=2 ; 
				continue; 
			}
		}
		s[i] = 'D' ; 
	}
	cout << s << "\n" ; 
	return 0 ; 
}