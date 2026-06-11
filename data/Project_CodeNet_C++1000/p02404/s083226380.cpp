#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  const string SHARP = "#";
  const string DOT = ".";
  vector <vector<int>> datas;
  while (true) {
    int H, W;
    cin >> H >> W;
    if (H == 0 && W == 0) {
      break;
    }
    vector<int> hw = { H, W };
    datas.push_back(hw);
  }

  for (int i = 0; i < (int)datas.size(); i++) {
    for (int j = 0; j < datas[i][0]; j++) {
      for (int k = 0; k < datas[i][1]; k++) {
        bool is_edge_row = j == 0 || j == datas[i][0] - 1;
        bool is_edge_column = k == 0 || k == datas[i][1] - 1;
        if (is_edge_row || is_edge_column) {
          cout << SHARP;
        } else {
          cout << DOT;
        }
      }
      cout << endl;
    }
    cout << endl;
  }
}
