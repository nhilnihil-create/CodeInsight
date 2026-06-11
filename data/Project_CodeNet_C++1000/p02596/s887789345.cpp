#include <iostream>
#include <string>

#define ll long long
#define repeat(i, x) for(register ll i = 0; i < x; i++)

using namespace std;

int main()
{
  ll ans = 0;

  ll N; cin >> N;

  if(N % 2 == 0) {
    cout << -1 << endl;
    return 0;
  }

  for(register ll i = 1; i <= N; i++) {
    ans = (ans * 10 + 7) % N;

    if(ans == 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}