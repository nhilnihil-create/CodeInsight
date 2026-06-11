#include <iostream>

using namespace std;

int main()
{
  int X,N;
  cin >> X >> N;
  if(N == 0)
  {
    cout << X << endl;
  }
  else
  {
    int a[N];
    for(int n = 0;n< N;n++)
    {
      cin >> a[n];
    }
    int iBuf;
    int iBuf2 = -1;
    for(int i=0;i < 101;i++)
    {
      iBuf = X - i;
      for(int j = 0;j < N;j++)
      {
        if(iBuf == a[j])
        {
          iBuf2 = iBuf;
        }
      }
      if(iBuf2 != iBuf)
      {
        break;
      }
      iBuf = X + i;
        for(int j = 0;j < N;j++)
      {
        if(iBuf == a[j])
        {
          iBuf2 = iBuf;
        }
      }
      if(iBuf2 != iBuf)
      {
        break;
      }
    }
    cout << iBuf << endl;
  }
  return 0;
}