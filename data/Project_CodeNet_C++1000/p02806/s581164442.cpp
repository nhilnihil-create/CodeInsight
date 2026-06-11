#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAX_N = 55;

int arr [MAX_N];

int main () {
  int n;
  cin >> n;

  map<string, int> idx;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s >> arr[i];

    idx[s] = i;
  }

  string x;
  cin >> x;

  int ans = 0;
  int st = idx[x] + 1;
  for (int i = st; i < n; i++) {
    ans += arr[i];
  }

  cout << ans << endl;
}
