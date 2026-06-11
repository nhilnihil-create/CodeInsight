#include<bits/stdc++.h>
using namespace std;
int main()
{
   int k;
   cin>>k;
   int sum = 0;
   for (int i = 1; i <= 2000006; i++) 
   {
        sum = (sum * 10 + 7) % k;
        if (sum == 0)
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
  return 0;
}  
