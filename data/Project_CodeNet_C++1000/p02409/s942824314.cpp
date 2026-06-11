#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n, bnum = 4, fnum = 3, rnum = 10;
  vector<int> rooms(bnum * fnum * rnum);
  cin >> n;

  for (int i = 0; i < n; i++) {
    int b, f, r, v;
    cin >> b >> f >> r >> v;
    int roomIndex = (b - 1) * fnum * rnum + (f - 1) * rnum + (r - 1);
    rooms[roomIndex] += v;
  }

  for (int i = 0; i < rooms.size(); i++) {
    cout << ' ' << rooms[i];
    if (i % rnum == rnum - 1) cout << endl;
    if (i % (fnum * rnum) == (fnum * rnum - 1) && i != rooms.size() - 1) {
      cout << string(20, '#') << endl;
    }
  }

  return 0;
}

