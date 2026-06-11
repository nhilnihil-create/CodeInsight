#include <iostream>
#include <vector>
using namespace  std;

void fnInsertionSort(vector<int> &a_rviSort, int a_iGap, int &a_riSortCnt)
{
  for (int ixSorting = a_iGap; ixSorting < a_rviSort.size() ; ixSorting++)
  {
    int iTarget = a_rviSort[ixSorting];
    int ixSorted = ixSorting - a_iGap;

    while (ixSorted >= 0              &&
           iTarget < a_rviSort[ixSorted])
    {
      a_rviSort[ixSorted + a_iGap] = a_rviSort[ixSorted];
      ixSorted -= a_iGap;

      a_riSortCnt++;
    }
    a_rviSort[ixSorted + a_iGap] = iTarget;
  }
}

void fnShellSort(vector<int> &a_rviSort, vector<int> &a_rviGap, int &a_riSortCnt)
{
  for (int iGap = 1; iGap <= a_rviSort.size(); iGap = 3 * iGap + 1)
    a_rviGap.push_back(iGap);
  
  for (int i = a_rviGap.size() - 1; i >= 0; i--)
    fnInsertionSort(a_rviSort, a_rviGap[i], a_riSortCnt);
}

void fnOutput(const vector<int> &a_cnrviSort, const vector<int> &a_cnrviGap, int a_iSortCnt)
{
  cout << a_cnrviGap.size() << endl;

  for (int i = a_cnrviGap.size() - 1; i >= 0; i--)
  {
    if (i != a_cnrviGap.size() - 1) cout << " ";
    cout << a_cnrviGap[i];
  }
  cout << endl;

  cout << a_iSortCnt << endl;

  for (int i = 0; i < a_cnrviSort.size(); i++)
    cout << a_cnrviSort[i] << endl;
}

int main()
{
  vector<int> viSort;
  vector<int> viGap;
  int iSortCnt = 0;
  int iMaxSize;
  
  cin >> iMaxSize;
  for (int i = 0; i < iMaxSize; i++)
  {
    int iNum;
    cin >> iNum;
    viSort.push_back(iNum);
  }

  fnShellSort(viSort, viGap, iSortCnt);
  fnOutput(viSort, viGap, iSortCnt);

  return 0;
}