#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
   string s;
   cin >> s;
   if (s == "SSS")
      cout << "0" << endl;
   if (s == "SSR")
      cout << "1" << endl;
   if (s == "SRS")
      cout << "1" << endl;
   if (s == "SRR")
      cout << "2" << endl;
   if (s == "RSS")
      cout << "1" << endl;
   if (s == "RSR")
      cout << "1" << endl;
   if (s == "RRS")
      cout << "2" << endl;
   if (s == "RRR")
      cout << "3" << endl;
}