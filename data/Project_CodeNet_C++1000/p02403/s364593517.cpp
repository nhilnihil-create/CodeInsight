#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  vector <vector<int>> datas;
  const string SHARP = "#";
  while (true) {
    int H, W;
    cin >> H >> W;
    if (H == 0 && W == 0) {
      break;
    }
    vector<int> hw = { H, W };
    datas.push_back(hw);
  }

  for (int i = 0; i < datas.size(); i++) {
    for (int j = 0; j < datas[i][0]; j++) {
      for (int k = 0; k < datas[i][1]; k++) {
        cout << SHARP;
      }
      cout << endl;
    }
    cout << endl;
  }
}
