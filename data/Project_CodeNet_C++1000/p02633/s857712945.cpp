#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
   int n;
   cin >> n;
   if (360%n==0)
   {
       cout << 360/n;
   }
   else
   {
       for (auto i=1; i<=100000; i++)
       {
           if (i*n%360==0)
           {
               cout << i;break;
           }
       }
   }
   return 0;
}