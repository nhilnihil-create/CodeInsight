#include <iostream>
#include <vector>

#define MAXNUM 200010

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> subordinates(MAXNUM, 0);
  int num, id;
  cin >> num;
  for (int i = 1; i < num; i++){
    cin >> id;
    subordinates[id]++;
  }
  for (int i = 1; i <= num; i++)
    cout << subordinates[i] << '\n';
  return 0;
}
