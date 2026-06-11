#include <iostream>
#include <string>

#define ll long long
#define repeat(i, x) for(register ll i = 0; i < x; i++)

using namespace std;

int main()
{
  int red = 0;
  int ans = 0;

  int N; cin >> N;
  string c; cin >> c;

  repeat(i, N) {
    if(c[i] == 'R') {
      red++;
    }
  }
  repeat(i, red) {
    if(c[i] == 'W') {
      ans++;
    }
  }

  cout << ans << endl;
}