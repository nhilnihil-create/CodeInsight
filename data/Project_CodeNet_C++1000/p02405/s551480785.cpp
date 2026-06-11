#include<iostream>

using namespace std;

string mark(int i, int j)
{
  if ( (i + j) % 2 == 0 )
    return "#";
  else
    return ".";
}

int main()
{
  int h, w;

  cin >> h >> w;

  while(true)
    {
      if ( h == 0 && w == 0 ) break;

      for ( int i = 0; i < h; i++ )
        {
          for ( int j = 0; j < w; j++ )
            {
              cout << mark(i, j);
            }
          cout << endl;
        }
      
      cout << endl;
      cin >> h >> w;
    }
  return 0;
}