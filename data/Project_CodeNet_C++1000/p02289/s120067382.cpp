#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// ---------------------
// repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

// debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

// ---------------------
#define INF 922337203685477580
typedef long long ll;

int H;

void maxHeapify(ll *A, int i) {
  int l = 2 * i;
  int r = 2 * i + 1;
  // ????????????????????????????????§???????????§????????????????????¶
  int largest = -11111;
  if (l <= H && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }
  if (r <= H && A[r] > A[largest]) {
    largest = r;
  }

  if (largest != i) {// i ???????????????????????§????????´???
    ll t = A[i];
    A[i] = A[largest];
    A[largest] = t;

    maxHeapify(A, largest); // ?????°??????????????????
  }
}

void buildMaxHeap(ll *A) {
  for (int i = H / 2; i >= 1; i--) {
    maxHeapify(A, i);
  }
}

void insert(ll *S, ll k) {
  H++;
  S[H] = k;

  int i = H;
  int parent = i / 2;
  while (i > 1 && S[parent] < S[i]) {
    swap(S[parent], S[i]);
    i = parent;
    parent = i / 2;
  }
}

ll extractMax(ll *S) {
  ll m = S[1];
  S[1] = S[H];
  H--;
  maxHeapify(S, 1);

  return m;
}

int main() {
  H = 0;
  ll A[2000000];

  while(1) {
    char cmd[20];
    // cin >> cmd;
    scanf("%s", cmd);

    if (cmd[0] == 'i') {  // insert
      ll key;
      // cin >> key;
      scanf("%lld", &key);

      insert(A, key);
    // } else if (cmd == "extract") {
    } else if (cmd[0] == 'e' && cmd[1] == 'x') {
      ll key = extractMax(A);
      // cout << key << endl;
      printf("%lld\n", key);
    } else {
      break;
    }
  }

  return 0;
}