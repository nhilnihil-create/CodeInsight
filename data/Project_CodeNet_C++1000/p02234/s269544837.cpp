#include <iostream>
#include <climits>
#include <vector>
using namespace  std;

void fnInput(vector<int>& rvnMtrx)
{
  int nMaxSiz;
  cin >> nMaxSiz;
  rvnMtrx.resize(nMaxSiz + 1);

  for (int i = 0; i < rvnMtrx.size() - 1; ++i)
    cin >> rvnMtrx[i] >> rvnMtrx[i + 1];
}

int fnMtrxChainMultpl(vector<vector<int>>& rvvnDetDP, const vector<int>& cnrvnMtrx)
{
  for (int i = 1; i < cnrvnMtrx.size(); ++i)  rvvnDetDP[i][i] = 0;

  const int cnMaxSiz = cnrvnMtrx.size() - 1;
  for (int nDif = 1; nDif <= cnMaxSiz - 1; ++nDif)
    for (int nRow = 1; nRow <= cnMaxSiz - nDif; ++nRow)
    {
      int nCol = nRow + nDif;
      for (int nx = nRow; nx <= nCol - 1; ++nx)
        rvvnDetDP[nRow][nCol] =
          min(rvvnDetDP[nRow][nCol],
              rvvnDetDP[nRow][nx] + rvvnDetDP[nx + 1][nCol] 
                                  + cnrvnMtrx[nRow - 1] * cnrvnMtrx[nx] * cnrvnMtrx[nCol]);
    }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<vector<int>> vvnDetDP; 
  vector<int> vnMtrx;

  fnInput(vnMtrx);
  vvnDetDP.resize(vnMtrx.size(), vector<int>(vnMtrx.size(), INT_MAX));

  fnMtrxChainMultpl(vvnDetDP, vnMtrx);
  cout << vvnDetDP[1][vnMtrx.size() - 1] << endl;
  return 0;
}