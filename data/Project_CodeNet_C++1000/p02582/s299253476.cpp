#include <bits/stdc++.h>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;
	cin >> s;
	int count = 0;
	if(s[0] == 'R')
	{
	    count = 1;
	    if(s[1]=='R')
        {
            count = 2;
            if(s[2] == 'R')
            {
                count = 3;
            }
        }
	}
	else if(s[1] == 'R')
    {
        count = 1;
        if(s[2] == 'R')
            count = 2;
    }
    else if(s[2] == 'R')
        count = 1;
    cout << count;
}
