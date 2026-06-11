#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void success () {
  cout << "Yes" << endl;
  exit(0);
}

void failure () {
  cout << "No" << endl;
  exit(0);
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  vector<pair<int, int>> blocks;
  for (int i = 0; i < n; i++) {
    if (i == 0 || arr[i] != arr[i - 1]) {
      blocks.push_back(make_pair(arr[i], 0));
    }
    blocks.back().second++;
  }

  if (n % 3 == 0) {
    if ((int) blocks.size() > 3) {
      failure();
    } else if ((int) blocks.size() == 3) {
      for (int k = 0; k < 3; k++) {
	if (blocks[k].second != n / 3) {
	  failure();
	}
      }

      if ((blocks[0].first ^ blocks[1].first) != blocks[2].first) {
	failure();
      }
      success();
    } else if ((int) blocks.size() == 2) {
      if (blocks[0].first != 0) {
	failure();
      }

      if (blocks[0].second != n / 3) {
	failure();
      }
      success();
    } else if ((int) blocks.size() == 1) {
      if (blocks[0].first != 0) {
	failure();
      }
      success();
    }
  } else {
    if (blocks[0].first == 0 && (int) blocks.size() == 1) {
      success();
    } else {
      failure();
    }
  }
}
