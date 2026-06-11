#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	
  	string s, t;
  	cin >> s >> t;
  	int m = s.length(), n = t.length(), same, ans = 0;
  	
  	for(int i = 0; i <= m-n; i++)
    {
      	same = 0;
      	for(int j = 0; j < n; j++)
          	if(s[i+j] == t[j])
              	same++;
      	ans = max(ans, same);
    }
  
  	cout << n-ans;
	return 0;
}
