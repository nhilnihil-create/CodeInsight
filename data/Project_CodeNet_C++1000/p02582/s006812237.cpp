
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{  
 
  string S ;
  cin >> S;

  int count = 0;
  int max = 0;

  for (int i = 0 ; i <=2 ; i++)
  {
      if (S[i]=='R')count++;
      if (max<count)max=count;      
      else count = 0;
  }
 
 cout << max;

 return 0;
}



