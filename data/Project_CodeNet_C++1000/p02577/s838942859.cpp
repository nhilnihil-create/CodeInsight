#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vint;
typedef vector<vint> vvint;

static string n;

int main()
{
	while(cin >> n){
		int res = 0;
        for(char i:n){
            res += i - '0';
        }

        if (res % 9 == 0)
            cout << "Yes\n";
        else
        {
            cout << "No\n";
        }        
	}
	
	return 0;
}
