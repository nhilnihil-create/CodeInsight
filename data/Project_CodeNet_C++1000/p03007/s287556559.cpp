/*
ID: skipian1
PROB: 
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF = 2000000000
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define X first
#define Y second

int main() {
  int n, cut;
  cin >> n;
  int arr[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += abs(arr[i]);
  }
  sort(arr, arr+n);
  if (arr[0] <= 0 && arr[n-1] >= 0) {
    cout << sum << "\n";
    cut = n-1;
    for (int i = 1; i < n-1; i++) {
      if (arr[i] >= 0) {
	cut = i;
	break;
      }
    }
    int cur = arr[0];
    for (int i = cut; i < n-1; i++){ 
      cout << cur << " " << arr[i] << "\n";
      cur -= arr[i];
    }
    cout << arr[n-1] << " " << cur << "\n";
    cur = arr[n-1] - cur;
    for (int i = 1; i < cut; i++) {
      cout << cur << " " << arr[i] << "\n";
      cur -= arr[i];
    }
  } else if (arr[n-1] < 0) {
    cout << sum+2*arr[n-1] << "\n";
    int cur = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
      cout << cur << " "  << arr[i] << "\n";
      cur -= arr[i];
    }
  } else {
    cout << sum-2*arr[0] << "\n";
    int cur = arr[0];
    for (int i = 1; i < n-1; i++) {
      cout << cur << " "  << arr[i] << "\n";
      cur -= arr[i];
    }
    cout << arr[n-1] << " " << cur << "\n";
  }
}
