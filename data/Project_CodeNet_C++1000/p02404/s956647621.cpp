#include<iostream>

using namespace std;

int main()
{
  int h, w;

  cin >> h >> w;

  while(true)
    {
      if (h == 0 && w == 0) break;

      for (int i = 0; i < h; i++)
        {
          if (i == 0 || i == h-1)
            {
              for (int j = 0; j < w; j++)
                {
                  cout << "#";
                }
              cout << endl;
            }
          else
            {
              for (int j = 0; j < w; j++)
                {
                  if (j == 0 || j == w-1)
                    {
                      cout << "#";
                    }
                  else
                    {
                      cout << ".";
                    }
                }
              cout << endl;
            }
        }
      cout << endl;
      cin >> h >> w;
    }
  
  return 0;
}