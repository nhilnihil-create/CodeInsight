#include <iostream>
#include <vector>
#include <climits>
using namespace  std;

#define llong long long

void fnInput(int &rnMaxSiz, vector<llong> &rvnSort)
{
  cin >> rnMaxSiz;

  rvnSort.resize(rnMaxSiz);
  for (int i = 0; i < rnMaxSiz; i++)
    cin >> rvnSort[i];
}

void fnMerge(vector<llong> &rvnSort, llong &rnInvCnt, int nLeft, int nMid, int nRight)
{
  vector<llong> vnLeft, vnRight;
  int nLeftSiz = nMid - nLeft;
  int nRightSiz = nRight - nMid;
  
  vnLeft.resize(nLeftSiz + 1);
  vnRight.resize(nRightSiz + 1);
  for (int i = 0; i < nLeftSiz; i++)
    vnLeft[i] = rvnSort[nLeft + i];
  for (int i = 0; i < nRightSiz; i++)
    vnRight[i] = rvnSort[nMid + i];

  vnLeft[nLeftSiz] = LLONG_MAX;
  vnRight[nRightSiz] = LLONG_MAX;

  int i = 0, j = 0;
  for (int n = nLeft; n < nRight; n++)
    if (vnLeft[i] <= vnRight[j])
      rvnSort[n] = vnLeft[i++];
    else
    {
      rvnSort[n] = vnRight[j++];
      if (vnLeft[i] != INT_MAX)
        rnInvCnt += (nLeftSiz - i);
      else;
    }  
}

void fnMergeSort(vector<llong> &rvnSort, llong &rnInvCnt, int nLeft, int nRight)
{
  if (nLeft + 1 < nRight)
  {
    int nMid = (nLeft + nRight) / 2;
    fnMergeSort(rvnSort, rnInvCnt, nLeft, nMid);
    fnMergeSort(rvnSort, rnInvCnt, nMid, nRight);
    fnMerge(rvnSort, rnInvCnt, nLeft, nMid, nRight);
  }
}

void fnResult(llong nInvCnt)
{
  cout << nInvCnt << endl; 
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int nMaxSiz;
  vector<llong> vnSort;

  fnInput(nMaxSiz, vnSort);

  int nLeft = 0;
  int nRight = nMaxSiz;
  llong nInvCnt = 0;
  fnMergeSort(vnSort, nInvCnt, nLeft, nRight);

  fnResult(nInvCnt);

  return 0;
}