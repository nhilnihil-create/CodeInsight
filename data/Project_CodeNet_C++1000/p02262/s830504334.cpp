#include <iostream>
#include <vector>
using namespace  std;

void fnInsertionSort(vector<int> &rvnSort, int nGap, int &rnSortCnt)
{
  for (int nSorting = nGap; nSorting < rvnSort.size() ; nSorting++)
  {
    int nTrg = rvnSort[nSorting];
    int nSorted = nSorting - nGap;

    while (nSorted >= 0         &&
           nTrg < rvnSort[nSorted])
    {
      rvnSort[nSorted + nGap] = rvnSort[nSorted];
      nSorted -= nGap;

      rnSortCnt++;
    }
    rvnSort[nSorted + nGap] = nTrg;
  }
}

void fnShellSort(vector<int> &rvnSort, vector<int> &rvnGap, int &rnSortCnt)
{
  for (int nGap = 1; nGap <= rvnSort.size(); nGap = 3 * nGap + 1)
    rvnGap.push_back(nGap);
  
  for (int i = rvnGap.size() - 1; i >= 0; i--)
    fnInsertionSort(rvnSort, rvnGap[i], rnSortCnt);
}

void fnOutput(const vector<int> &cnrvnSort, const vector<int> &cnrvnGap, int nSortCnt)
{
  cout << cnrvnGap.size() << endl;

  for (int i = cnrvnGap.size() - 1; i >= 0; i--)
  {
    if (i != cnrvnGap.size() - 1) cout << " ";
    cout << cnrvnGap[i];
  }
  cout << endl;

  cout << nSortCnt << endl;

  for (int i = 0; i < cnrvnSort.size(); i++)
    cout << cnrvnSort[i] << endl;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<int> vnSort;
  vector<int> vnGap;
  int nSortCnt = 0;
  int nMaxSiz;
  
  cin >> nMaxSiz;
  for (int i = 0; i < nMaxSiz; i++)
  {
    int nNum;
    cin >> nNum;
    vnSort.push_back(nNum);
  }

  fnShellSort(vnSort, vnGap, nSortCnt);
  fnOutput(vnSort, vnGap, nSortCnt);

  return 0;
}