#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
class Processes
{
public:
  string sName;
  int iProcessTime;

};



int main(int argc, char *argv[])
{
  int iProcessNum;  		// プロセスの個数
  int iProcessTime;		// プロセスに書けることのできる時間
  int time = 0;

  queue<Processes> qu;
  cin >> iProcessNum >> iProcessTime;

  for (int i = 0; i < iProcessNum ; i++) {
    Processes ps;
    cin >> ps.sName >> ps.iProcessTime;
    qu.push(ps);
  }

  while (true) {
    if (qu.size() == 0) {
      break;
    }
    // for (int i = 0; i < qu.size() ; i++) {
    //   Processes ps = qu.front();
    //   qu.pop();
    //   cout << ps.sName << " "<< ps.iProcessTime  << "\n";
    //   qu.push(ps);

    // }
    // cout << "" << "\n";
    
    Processes ps = qu.front();
    qu.pop();

    
    if (ps.iProcessTime <= iProcessTime) {
      time = time + ps.iProcessTime;
      cout <<ps.sName << " " << time << "\n";
    }else {
      ps.iProcessTime = ps.iProcessTime - iProcessTime;
      time = time + iProcessTime;
      qu.push(ps);
    }
    
  }
  // cout << iProcessNum << " " << iProcessTime << "\n";

  return 0;
}

