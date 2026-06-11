#include<bits/stdc++.h>
using namespace std;

int main()
{
 string s;
 cin >> s;
 long long int ans = 0;
 for(int i = 0; i < s.size(); i++)
    {
        ans+=(s[i] - '0');
    }
if(ans%9) cout<<"No";
else cout<<"Yes";
  return 0;
}
