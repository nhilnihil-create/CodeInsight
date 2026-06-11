#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

typedef tuple<int, int, int> Rect;

int main() {
  vector<Rect> rects;
  for (int h = 1; h < 150; h++) {
    for (int w = h + 1; w < 150; w++) {
      rects.push_back(Rect(w * w + h * h, h, w));
    }
  }

  sort(rects.begin(), rects.end());
  
  int h, w;
  while (cin >> h >> w && h) {
    Rect r = Rect(w * w + h * h, h, w);
    auto u = upper_bound(rects.begin(), rects.end(), r);
    Rect bigr = *u;
    cout << get<1>(bigr) << " " << get<2>(bigr) << endl;
  }
}