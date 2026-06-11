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
  vector<int> P(N);
  vector<int> Q(N);
  vector<int> length(N);
  int a = 0;
  int b = 0;

  for (register int i = 0; i < N; i++) {
    cin >> P[i];
    length[i] = i+1;
  }
  for (register int i = 0; i < N; i++) {
    cin >> Q[i];
  }

  int count = 0;

  do {
    count++;
    if(length == P) {
      a = count;
    }

    if (length == Q) {
      b = count;
    }

  } while(next_permutation(length.begin(), length.end()) && (a==0 || b==0));

  cout << abs(a - b) << endl;
}