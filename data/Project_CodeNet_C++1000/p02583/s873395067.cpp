#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main()
{
   int n;
   cin >> n;

   int count = 0;
   vector<int> v(n);

   for (int i = 0; i < n; i++)
   {
      cin >> v.at(i);
   }

   sort(v.begin(), v.end());

   for (int i = 0; i < n - 2; i++)
   {
      for (int j = i; j < n - 1; j++)
      {
         for (int k = j; k < n; k++)
         {
            if (v.at(i) + v.at(j) > v.at(k) &&v.at(i)!=v.at(j)&& v.at(i)!=v.at(k)&&v.at(j)!=v.at(k))
            {
               count++;
            }
         }
      }
   }
   cout << count << endl;
}