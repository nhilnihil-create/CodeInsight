#include <iostream>
using namespace std;

int main()
{
  int N, A[3][3];
  for(int i = 0; i < 3; ++i)
  {
    for(int j = 0; j < 3; ++j)
    {
      cin >> A[i][j];
    }
  }

  bool punch[3][3] = {false};
  cin >> N;
  for(int i = 0; i < N; ++i)
  {
    int a;
    cin >> a;
    for(int r = 0; r < 3; ++r)
    {
      for(int c = 0; c < 3; ++c)
      {
        if(A[r][c] == a)
        {
          punch[r][c] = true;
        }
      }
    }
  }
  
  bool bingo = false;
  for(int i = 0; i < 3; ++i)
  {
    if(punch[i][0] && punch[i][1] && punch[i][2])
    {
      bingo = true;
    }
    if(punch[0][i] && punch[1][i] && punch[2][i])
    {
      bingo = true;
    }
  }
  if((punch[0][0] && punch[1][1] && punch[2][2]) ||
     (punch[0][2] && punch[1][1] && punch[2][0]))
  {
    bingo = true;
  }
  
  if(bingo)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  
}