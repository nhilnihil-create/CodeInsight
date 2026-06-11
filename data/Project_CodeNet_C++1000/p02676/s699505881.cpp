#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	int k;
  	string s,ans;
  	cin >> k >> s;
  	if(s.length()>k){
      ans = s.substr(0,k);
      ans = ans + "...";
    }
    else
      ans = s;
  	cout << ans;
    return 0;
}