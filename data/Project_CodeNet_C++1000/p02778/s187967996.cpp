#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
   string str;
   cin >> str;
   char s[str.size()];
   strcpy(s,str.c_str());
   memset(s, 'x', sizeof(s));
   cout << s;
}
