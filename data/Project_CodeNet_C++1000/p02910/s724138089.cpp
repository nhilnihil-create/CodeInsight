#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	string s;
	cin>>s;
	bool easy=0;
	for (int i = 0; i <SZ(s); ++i)
		{
			bool x = (i%2==0);


			if(x&&s[i]=='L') {
				puts("No");
				return 0;
			} 
			if(!x&&s[i]=='R'){
				puts("No");
				return 0;
				
			}

		}	
    puts("Yes");
   return 0;
}
