#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int a[sz];

int main()
{
   string s;
   cin >> s;
   for(int i=0; i<s.size(); i++)
      if(s[i] == '?') s[i] = 'D';
   cout << s << endl;
}
