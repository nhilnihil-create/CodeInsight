#include <iostream>
#include <vector>
#include <string>
using namespace  std;

void fnBubbleSort(vector<string> &argvsSortBbl)
{
  int ixSorting = 0;
  bool bSorting = true;

  while (bSorting)
  {
    bSorting = false;
    for (int j = argvsSortBbl.size() - 1; j > ixSorting; j--)
    {
      if (argvsSortBbl[j].at(1) < argvsSortBbl[j - 1].at(1))
      {
        swap(argvsSortBbl[j], argvsSortBbl[j - 1]);
        bSorting = true;
      }
    }
    ixSorting++;
  }
}

void fnOutputBbl(const vector<string> &argvsSortBbl)
{
  for (int i = 0; i < argvsSortBbl.size(); i++)
  {
    if (i) cout << " ";
    cout << argvsSortBbl[i];
  }
  cout << endl;
  cout << "Stable" << endl;
}

void fnSelectionSort(vector<string> &argvsSortSel)
{
  for (int ixSorting = 0; ixSorting < argvsSortSel.size() - 1; ixSorting++)
  {
    int ixMinimum = ixSorting;
    bool bSorting = false;
    for (int j = ixSorting + 1; j < argvsSortSel.size(); j++)
    {
      if (argvsSortSel[j].at(1) < argvsSortSel[ixMinimum].at(1))
      {
        ixMinimum = j;
        bSorting = true;
      }
    }
    if (bSorting == true)
    {
      swap(argvsSortSel[ixSorting], argvsSortSel[ixMinimum]);
    }
  }
}

void fnOutputSel(const vector<string> &argvsSortSel, const vector<string> &argvsSortBbl)
{
  string sSortEnd = "Stable";

  for (int i = 0; i < argvsSortSel.size(); i++)
  {
    if (i) cout << " ";
    cout << argvsSortSel[i];
    
    if (argvsSortSel[i] != argvsSortBbl[i]) sSortEnd = "Not stable";
  }
  cout << endl;
  cout << sSortEnd << endl;
}

int main()
{
  vector<string> vsSortBbl, vsSortSel;
  int iMaxSize;
  
  cin >> iMaxSize;
  for (int i = 0; i < iMaxSize; i++)
  {
    string sCard;
    cin >> sCard;
    vsSortBbl.push_back(sCard);
    vsSortSel.push_back(sCard);
  }

  fnBubbleSort(vsSortBbl);
  fnOutputBbl(vsSortBbl); 

  fnSelectionSort(vsSortSel);
  fnOutputSel(vsSortSel, vsSortBbl);

  return 0;
}