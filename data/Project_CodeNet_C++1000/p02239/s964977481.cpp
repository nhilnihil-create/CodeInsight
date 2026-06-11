#include <iostream>
#include <vector>
#include <queue>
using namespace  std;

const int nIMPOS = -1;
struct StDist
{
  int m_nDist;
  int m_nDone;

  StDist(int nDist) : m_nDist(nDist), m_nDone(0)
  { }
};

void fnInput(vector<vector<int>>& rvvnAdjcy, vector<StDist>& rvoDist)
{
  int nxSiz;
  cin >> nxSiz;

  rvvnAdjcy.resize(nxSiz + 1, vector<int>(nxSiz + 1, 0));
  for (int i = 0; i < nxSiz; ++i)
  {
    int nx, nySiz;
    cin >> nx >> nySiz;
    for (int j = 0; j < nySiz; ++j)
    {
      int ny;
      cin >> ny;
      rvvnAdjcy[nx][ny] = 1;
    }
  }
  StDist oDist(nIMPOS);
  rvoDist.resize(nxSiz + 1, oDist);
}

void fnBreadthFirstSearch(const vector<vector<int>>& cnrvvnAdjcy, 
                          queue<int>& rqnBFSrch, vector<StDist>& rvoDist)
{
  while (rqnBFSrch.size())
  {
    int nx = rqnBFSrch.front(); rqnBFSrch.pop();
    if (rvoDist[nx].m_nDist == nIMPOS)  continue;

    for (int ny = 1; ny < cnrvvnAdjcy[nx].size(); ++ny)
    {
      if (cnrvvnAdjcy[nx][ny] == 1  &&
          rvoDist[nx].m_nDone == 0)
      {
        int nDist = rvoDist[nx].m_nDist + 1;
        if (rvoDist[ny].m_nDist == nIMPOS)
          rvoDist[ny].m_nDist = nDist;
        else
          rvoDist[ny].m_nDist = min(rvoDist[ny].m_nDist, nDist);

        rqnBFSrch.push(ny);
      }
    }
    rvoDist[nx].m_nDone = 1;
  }
}

void fnResult(const vector<StDist>& cnrvoDist)
{
  for (int i = 1; i < cnrvoDist.size(); ++i)
    cout << i <<  " " << cnrvoDist[i].m_nDist << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<vector<int>> vvnAdjcy;
  queue<int>  qnBFSrch;
  vector<StDist> voDist;

  fnInput(vvnAdjcy, voDist);

  voDist[1].m_nDist = 0;
  qnBFSrch.push(1);
  fnBreadthFirstSearch(vvnAdjcy, qnBFSrch, voDist);
  fnResult(voDist);

  return 0;
}