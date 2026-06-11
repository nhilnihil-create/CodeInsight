#include <iostream>
#include <queue>
#include <string>
using namespace  std;

typedef pair<string, int> PAIR;

void fnInput(int &a_riMaxProc, int &a_riQuantum, queue<PAIR> &a_rqPProcess)
{
  cin >> a_riMaxProc >> a_riQuantum;
  
  for (int i = 0; i < a_riMaxProc; i++)
  {
    string sProcName;
    int iProcTime;
    cin >> sProcName >> iProcTime;
    a_rqPProcess.push(PAIR(sProcName, iProcTime));
  }
}

void fnSchedule(int a_iQuantum, queue<PAIR> &a_rqPProcess)
{
  int iTotalTime = 0;
  while (a_rqPProcess.size())
  {
    PAIR PProcess = a_rqPProcess.front(); a_rqPProcess.pop(); 
    if (PProcess.second > a_iQuantum)
    {
      PProcess.second -= a_iQuantum;
      a_rqPProcess.push(PProcess);
      iTotalTime += a_iQuantum;
    }
    else
    {
      iTotalTime += PProcess.second;
      cout << PProcess.first << " " << iTotalTime << endl;
    }
  }
}

int main()
{
  int iMaxProc, iQuantum;
  queue<PAIR> qPProcess;
  
  fnInput(iMaxProc, iQuantum, qPProcess);
  fnSchedule(iQuantum, qPProcess);

  return 0;
}