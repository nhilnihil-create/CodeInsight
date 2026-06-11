#include <iostream>
#include <vector>
using namespace  std;

void fnInput(int &a_riElementCnt, vector<int> &a_rviElement, 
             int &a_riTargetCnt , vector<int> &a_rviTarget )
{
  cin >> a_riElementCnt;

  a_rviElement.resize(a_riElementCnt);
  for (int i = 0; i < a_riElementCnt; i++)
    cin >> a_rviElement[i];

  cin >> a_riTargetCnt;

  a_rviTarget.resize(a_riTargetCnt);
  for (int i = 0; i < a_riTargetCnt; i++)
    cin >> a_rviTarget[i];
}

int fnRcsSearch(int a_iPos, const vector<int> &a_cnrviElement, int a_iTarget,
                vector<vector<int>> &a_rvviOK)
{
  if (a_iPos == a_cnrviElement.size())  return 0;
  if (!a_iTarget)    return 1;
  if (a_iTarget < 0) return 0;
  if (a_rvviOK[a_iPos][a_iTarget] != -1)
  {
    return a_rvviOK[a_iPos][a_iTarget];
  }

  a_iPos++; 
  int iRtn0 = fnRcsSearch(a_iPos, a_cnrviElement, a_iTarget, a_rvviOK);
  a_rvviOK[a_iPos][a_iTarget] = iRtn0;
  if (iRtn0)  return iRtn0;

  int iSmallTarget = a_iTarget - a_cnrviElement[a_iPos];
  int iRtn1 = fnRcsSearch(a_iPos, a_cnrviElement, iSmallTarget, a_rvviOK);
  if (iSmallTarget >= 0)
  {
    a_rvviOK[a_iPos][iSmallTarget] = iRtn1;
    return iRtn1;
  }
}

void fnExhSearch(const vector<int> &a_cnrviElement, const vector<int> &a_cnrviTarget)
{
  vector<vector<int>> vviOK(21, vector<int>(2001, -1));
  
  for (int i = 0; i < a_cnrviTarget.size(); i++)
  {
    int iTarget = a_cnrviTarget[i];
    int iRtn0, iRtn1;

    if (fnRcsSearch(0, a_cnrviElement, iTarget, vviOK))
    {
      cout << "yes" << endl;
      vviOK[0][iTarget] = fnRcsSearch(0, a_cnrviElement, iTarget, vviOK);
      continue;
    }

    int iSmallTarget = iTarget - a_cnrviElement[0];
    if (fnRcsSearch(0, a_cnrviElement, iSmallTarget, vviOK))
      cout << "yes" << endl;
    else
      cout << "no" << endl;

    if (iSmallTarget >= 0)
    {
      vviOK[0][iSmallTarget] = fnRcsSearch(0, a_cnrviElement, iSmallTarget, vviOK);
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int iElementCnt, iTargetCnt;
  vector<int> viElement, viTarget;

  fnInput(iElementCnt, viElement, iTargetCnt, viTarget);
  fnExhSearch(viElement, viTarget);

  return 0;
}