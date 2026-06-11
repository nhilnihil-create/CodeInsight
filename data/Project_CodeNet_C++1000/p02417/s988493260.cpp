#include<iostream>

using namespace std;

int main()
{
  char c;

  int st[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  
  while( cin >> c )
    {
      if ( c >= 'a' && c <= 'z' )
        {
          st[c - 'a']++;
        }
      else if ( c >= 'A' && c <= 'Z' )
        {
          st[c - 'A']++;
        }
    }

  for ( char i = 'a'; i <= 'z'; i++)
    {
      cout << i << " : " << st[i - 'a'] << endl;
    }
  
  return 0;
}