#include <bits/stdc++.h>

using namespace std;

int NUMBERS[101][2];
int A[4][4];
int R[4][4];
int B[10];

int main()
{
  int N;

  for (int i = 1; i < 4; i++)
  {
    for (int j = 1; j < 4; j++)
    {
      cin >> A[i][j];
      NUMBERS[A[i][j]][0] = i;
      NUMBERS[A[i][j]][1] = j;
    }
  }
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> B[i];
    if (NUMBERS[B[i]][0] != 0 && NUMBERS[B[i]][1] != 0)
    {
      R[NUMBERS[B[i]][0]][NUMBERS[B[i]][1]] = 1;
    }
  }

  if ((R[1][1] == 1 && R[1][2] == 1 && R[1][3] == 1) ||
      (R[2][1] == 1 && R[2][2] == 1 && R[2][3] == 1) ||
      (R[3][1] == 1 && R[3][2] == 1 && R[3][3] == 1) ||
      (R[1][1] == 1 && R[2][1] == 1 && R[3][1] == 1) ||
      (R[1][2] == 1 && R[2][2] == 1 && R[3][2] == 1) ||
      (R[1][3] == 1 && R[2][3] == 1 && R[3][3] == 1) ||
      (R[1][1] == 1 && R[2][2] == 1 && R[3][3] == 1) ||
      (R[1][3] == 1 && R[2][2] == 1 && R[1][3] == 1))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
