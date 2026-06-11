#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  vector< pair<int, int> > gem;

  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      gem.push_back(pair<int, int>(a, b));
    }

    cin >> m;
    int x = 10, y = 10;
    for (int i = 0; i < m; i++) {
      char news;
      int len;
      cin >> news >> len;
      if (news == 'N') {
        vector< pair<int, int> >::iterator itr = find(gem.begin(), gem.end(), pair<int, int>(x, y));
        if (itr != gem.end()) {
          gem.erase(itr);
        }
        for (int j = 0; j < len; j++) {
          y++;
          itr = find(gem.begin(), gem.end(), pair<int, int>(x, y));
          if (itr != gem.end()) {
            gem.erase(itr);
          }
        }
      } else if (news == 'E') {
        vector <pair<int, int> >::iterator itr = find(gem.begin(), gem.end(), pair<int, int>(x, y));
        if (itr != gem.end()) {
          gem.erase(itr);
        }
        for (int j = 0; j < len; j++) {
          x++;
          itr = find(gem.begin(), gem.end(), pair<int, int>(x, y));
          if (itr != gem.end()) {
            gem.erase(itr);
          }
        }
      } else if (news == 'W') {
        vector <pair<int, int> >::iterator itr = find(gem.begin(), gem.end(), pair<int, int>(x, y));
        if (itr != gem.end()) {
          gem.erase(itr);
        }
        for (int j = 0; j < len; j++) {
          x--;
          itr = find(gem.begin(), gem.end(), pair<int, int>(x, y));
          if (itr != gem.end()) {
            gem.erase(itr);
          }
        }
      } else {
        vector <pair<int, int> >::iterator itr = find(gem.begin(), gem.end(), pair<int, int>(x, y));
        if (itr != gem.end()) {
          gem.erase(itr);
        }
        for (int j = 0; j < len; j++) {
          y--;
          itr = find(gem.begin(), gem.end(), pair<int, int>(x, y));
          if (itr != gem.end()) {
            gem.erase(itr);
          }
        }
      }
    }
    cout << (gem.empty() ? "Yes" : "No") << endl;
    gem.clear();
  }
  return 0;
}