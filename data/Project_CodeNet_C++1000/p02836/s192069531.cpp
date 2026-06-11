#include <bits/stdc++.h>

using namespace std;

int main()
{
   string s;
   cin >> s;

   int count = 0;
   int len = s.length();

   for (int i = 0; i < len / 2; i++)
   {
      if (s.at(i) != s.at(len - 1 - i))
         count++;
   }
   cout << count << endl;
}
