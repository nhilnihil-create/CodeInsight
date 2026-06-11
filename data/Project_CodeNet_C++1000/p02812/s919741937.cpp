#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#define ll long long
#define repeat(i, x) for(register ll i = 0; i < x; i++)

using namespace std;

int main()
{
  int N; cin >> N;
  string S; cin >> S;
  int count = 0;

  for (int i = 0; i <= S.size() - 3; i++) {
    if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C') {
      count++;
    }
  }

  cout << count << endl;
}