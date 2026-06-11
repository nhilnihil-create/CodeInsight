#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
using namespace  std;

const int MAXSIZE = 100000;
const int END = -1;
struct StNod
{
  bool m_bBe;
  int m_nDept;
  int m_nParnt;
  int m_nLChd;
  int m_nRSib;

  StNod() :
    m_bBe(false), m_nDept(0), m_nParnt(END), m_nLChd(END), m_nRSib(END)
  { }
};

void fnInput(int &rnMaxSiz, vector<StNod> &rvoNod)
{
  StNod oNod;
  rvoNod.resize(MAXSIZE, oNod);

  cin >> rnMaxSiz;

  for (int i = 0; i < rnMaxSiz; i++)
  {
    int nParnt, nCCnt, nChd, nBChd = END;
    cin >> nParnt >> nCCnt;
    rvoNod[nParnt].m_bBe = true;
    for (int j = 0; j < nCCnt; j++)
    {
      cin >> nChd;
      rvoNod[nChd].m_bBe = true;
      rvoNod[nChd].m_nParnt = nParnt;
      if (nBChd != END) rvoNod[nBChd].m_nRSib = nChd;
      if (!j)          rvoNod[nParnt].m_nLChd = nChd;
      nBChd = nChd;
    }
  }
}

void fnSetDepth(vector<StNod> &rvoNod, int nx, int nDept)
{
  rvoNod[nx].m_nDept = nDept;
  
  if (rvoNod[nx].m_nRSib != END)
    fnSetDepth(rvoNod, rvoNod[nx].m_nRSib, nDept);

  if (rvoNod[nx].m_nLChd != END)
    fnSetDepth(rvoNod, rvoNod[nx].m_nLChd, nDept + 1);
}

void fnRtdTree(vector<StNod> &rvoNod)
{
  int nx = 0, nDept = 0;
  while (rvoNod[nx].m_nParnt != END)
    nx = rvoNod[nx].m_nParnt;

  fnSetDepth(rvoNod, nx, nDept);
}

void fnResult(const vector<StNod> &cnrvoNod)
{
  for (int i = 0; cnrvoNod[i].m_bBe; i++)
  {
    cout << "node " << i << ": parent = " << cnrvoNod[i].m_nParnt << ", depth = " << cnrvoNod[i].m_nDept;

    if (!cnrvoNod[i].m_nDept)            cout << ", root, ";
    else if (cnrvoNod[i].m_nLChd == END) cout << ", leaf, ";
    else                                 cout << ", internal node, ";

    cout << "[";
    if (cnrvoNod[i].m_nLChd != END)
    {
      int nx = cnrvoNod[i].m_nLChd;
      cout << nx;
      while (cnrvoNod[nx].m_nRSib != END)
      {
        cout << ", " << cnrvoNod[nx].m_nRSib;
        nx = cnrvoNod[nx].m_nRSib;
      }
    }
    cout << "]" << endl;
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int nMaxSiz;
  vector<StNod> voNod;

  fnInput(nMaxSiz, voNod);
  fnRtdTree(voNod);
  fnResult(voNod);
  return 0;
}