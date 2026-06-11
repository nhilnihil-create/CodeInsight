#include <bits/stdc++.h>

using namespace std;

int main()
{
   int x;
   int sum = 0;
   for (int i = 0; i < 3; i++)
   {
      cin >> x;
      sum += x;
   }

   if (sum > 21)
      cout << "bust" << endl;
   else
      cout << "win" << endl;
}
