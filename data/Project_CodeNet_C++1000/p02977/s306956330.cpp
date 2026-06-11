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
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

int N;
int A[1<<20];

void mod3() {
  cout << "Yes" << endl;
  for(int i = 1;i < N;i++) {
    cout << i << " " << i + 1 << endl;
    cout << N + i << " " << N + i + 1 << endl;
  }
  cout << N << " " << N + 1 << endl;
}

void mod0() {
  if((N & (N - 1)) == 0) {
    cout << "No" << endl;
    return;
  }

  cout << "Yes" << endl;
  for(int i = 1;i < N;i++) {
    A[i] = i;
  }

  int x = (N & (N-1));
  int y = N - x;

  swap(A[1], A[x]);
  swap(A[2], A[y]);

  for(int i = 1; i < (N-1);i++) {
    cout << A[i] << " " << A[i+1] << endl;
    cout << N + A[i] << " " << N + A[i+1] << endl;
  }
  cout << A[N-1] << " " << N + A[1] << endl;
  cout << A[1] << " " << N << endl;
  cout << A[2] << " " << 2 * N << endl;
}

void mod1() {
  if((N & (N - 1)) == 0) {
    cout << "No" << endl;
    return;
  }

  cout << "Yes" << endl;
  for(int i = 1;i < N-1;i++) {
    A[i] = i;
  }

  int x = ((N - 1) & (N-2));
  int y = N - 1 - x;

  if(x != 0) {
    swap(A[2], A[x]);
    swap(A[3], A[y]);

    for(int i = 1; i < (N-2);i++) {
      cout << A[i] << " " << A[i+1] << endl;
      cout << N + A[i] << " " << N + A[i+1] << endl;
    }
    cout << A[N-2] << " " << N + A[1] << endl;
    cout << A[2] << " " << N - 1 << endl;
    cout << A[3] << " " << (2 * N - 1) << endl;
    cout << A[1] << " " << N << endl;
    cout << A[3] << " " << (2 * N) << endl;
  } else{
    for(int i = 1; i < (N-2);i++) {
      cout << A[i] << " " << A[i+1] << endl;
      cout << N + A[i] << " " << N + A[i+1] << endl;
    }
    cout << A[N-2] << " " << N + A[1] << endl;
    cout << 1 << " " << N-1 << endl;
    cout << N-1 << " " << N << endl;
    cout << 1 << " " << 2*N << endl;
    cout << 2*N << " " << 2*N-1 << endl;
  }
}

void mod2() {
  if((N & (N - 1)) == 0) {
    cout << "No" << endl;
    return;
  }

  cout << "Yes" << endl;
  for(int i = 1;i < N-2;i++) {
    A[i] = i;
  }

  int x = ((N - 2) & (N-3));
  int y = N - 2 - x;

  if(x != 0) {
    swap(A[2], A[x]);
    swap(A[3], A[y]);
    swap(A[x], A[4]);

    for(int i = 1; i < (N-3);i++) {
      cout << A[i] << " " << A[i+1] << endl;
      cout << N + A[i] << " " << N + A[i+1] << endl;
    }
    cout << A[N-3] << " " << N + A[1] << endl;
    cout << A[2] << " " << N - 2 << endl;
    cout << A[3] << " " << 2*N - 2 << endl;
    cout << A[1] << " " << N - 1 << endl;
    cout << A[3] << " " << 2*N - 1 << endl;
    cout << A[2] << " " << N << endl;
    cout << A[4] << " " << 2*N << endl;
  } else{
    for(int i = 1; i < (N-3);i++) {
      cout << A[i] << " " << A[i+1] << endl;
      cout << N + A[i] << " " << N + A[i+1] << endl;
    }
    cout << A[N-3] << " " << N + A[1] << endl;
    cout << 1 << " " << N-2 << endl;
    cout << N-2 << " " << N-1 << endl;
    cout << 1 << " " << 2*N-1 << endl;
    cout << 2*N-1 << " " << 2*N-2 << endl;
    cout << 2*N-1 << " " << 2*N << endl;
    cout << N << " " << 2 << endl;

  }
}

int main() {
  //freopen("input.in","r",stdin);
  //freopen("output.out","w",stdout);

  cin >> N;

  if(N % 4 == 3) {
    mod3();
    return 0;
  }

  if(N % 4 == 0) {
    mod0();
    return 0;
  }

  if(N % 4 == 1) {
    mod1();
    return 0;
  }

  if(N % 4 == 2) {
    mod2();
    return 0;
  }


  return 0;
}
