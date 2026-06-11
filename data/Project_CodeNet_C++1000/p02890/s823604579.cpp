#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

#define debug(x) cout << #x << ": " << x << endl;
#define ll long long
#define mod 1000000007

int N, A[1 << 20], num, B[1 << 20], C[1 << 20], D[1 << 20];

int main() {
 // freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    cin >> num;
    A[num]++;
  }
  int counter = 0;
  for (size_t i = 1; i <= N; i++) {
    if(A[i] > 0) {
      counter++;
      B[A[i]]++;
    }
  }
  int l_counter = 0;
  int l_ans = 0;
  for (size_t i = 1; i <= N; i++) {
    l_counter += B[i];
    l_ans += B[i]*i;
    C[i] = ((counter-l_counter)*i + l_ans)/i;
  }

  // for(int i = 0;i < N;i++) cout<<C[i+1]<<" "
  for(int i = N; i > 0;i--) {
    if(D[C[i]] == 0) {
      D[C[i]] = i;
    }
  }

  for(int i = N-1;i > 0;i--) {
    if(D[i] == 0) D[i] = D[i+1];
  }

  for (size_t i = 0; i < N; i++) {
    cout << D[i+1] << endl;
  }

  return 0;
}
