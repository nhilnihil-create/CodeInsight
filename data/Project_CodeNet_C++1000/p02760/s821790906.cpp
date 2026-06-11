#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isBingo(vector<bool> board)
{
  for(int i=0; i<3; i++)
  {
    if(board[i] && board[i + 3] && board[i + 6])
      return true;
    if(board[i*3] && board[i*3 + 1] && board[i*3 + 2])
      return true;
  }
  if(board[0] && board[4] && board[8] || board[2] && board[4] && board[6])
    return true;
  
  return false;
}

int main()
{
  vector<int> board_num(9);
  vector<bool> board(9);
  int n;
  string res = "No";
  for(int i=0; i<board.size(); i++)
  {
    cin >> board_num[i];
    board[i] = false;
  }
  
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int b;
    cin >> b;
    vector<int>::iterator it = find(board_num.begin(), board_num.end(), b);
    if(it != board_num.end())
    {
      board[distance(board_num.begin(), it)] = true;
      if(isBingo(board))
      {
        res = "Yes";
        break;
      }
    }
  }
  
  cout << res << endl;
  return 0;
}