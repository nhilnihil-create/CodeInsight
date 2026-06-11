#include <bits/stdc++.h>

using namespace std;


void solve(){

  cout << fixed << setprecision(5);
  long long a, b;
  cin >> a >> b;
  double answer = (a + b) / 2.0;
  // 1.5 --> 15
  //cout << "Test " << (long long)(10.0 * answer) << endl;
  if((long long)(10.0 * answer) % 10 == 0){
    cout << (long long)answer << endl;
  }
  else{

  //  cout << answer << endl;
    cout << "IMPOSSIBLE" << endl;
  }

}

int main()
{
    solve();
    return 0;
}
