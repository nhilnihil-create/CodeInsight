#include <iostream>
#include <vector>
using namespace  std;

void fnInsertionSort(vector<int> &argviSort, int argiGap, int &argiSortCnt)
{
  for (int ixSorting = argiGap; ixSorting < argviSort.size() ; ixSorting++)
  {
    int iTarget = argviSort[ixSorting];
    int ixSorted = ixSorting - argiGap;

    while (ixSorted >= 0              &&
           iTarget < argviSort[ixSorted])
    {
      argviSort[ixSorted + argiGap] = argviSort[ixSorted];
      ixSorted -= argiGap;

      argiSortCnt++;
    }
    argviSort[ixSorted + argiGap] = iTarget;
  }
}

void fnShellSort(vector<int> &argviSort, vector<int> &argviGap, int &argiSortCnt)
{

  for (int iGap = 1; iGap < argviSort.size(); iGap = 3 * iGap + 1)
    argviGap.push_back(iGap);
  
  for (int i = argviGap.size() - 1; i >= 0; i--)
    fnInsertionSort(argviSort, argviGap[i], argiSortCnt);
}

void fnOutput(const vector<int> &argviSort, const vector<int> &argviGap, int argiSortCnt)
{
  if (argviGap.size() == 0)
  {
    cout << 1 << endl;                  // argviGap.size() ??? 1 ??¨??¨???
    cout << 1 << endl;                  // argviGap[0]     ??? 1 ??¨??¨???
  }
  else
  {
    cout << argviGap.size() << endl;

    for (int i = argviGap.size() - 1; i >= 0; i--)
    {
      if (i != argviGap.size() - 1) cout << " ";
      cout << argviGap[i];
    }
    cout << endl;
  }

  cout << argiSortCnt << endl;

  for (int i = 0; i < argviSort.size(); i++)
    cout << argviSort[i] << endl;
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