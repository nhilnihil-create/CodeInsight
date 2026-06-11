#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i, n, cnt = 0;
  cin >> n;
  int s[n+5];

  for(i = 1; i <= n; i++)
  	 cin >> s[i];

  for(i = 1; i <= n; i++)
    {
      if(s[i] != i) cnt ++;
    }

    if(cnt <= 2) cout << "YES";
    else cout << "NO";
   
}