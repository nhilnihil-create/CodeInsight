#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 300010

int counter[SIZE];
int num[SIZE];
int A[SIZE];

vector<int> naive(int N) {
  vector<int> ans;

  for (int i=0; i<=N; i++) {
    counter[i] = 0;
    num[i] = 0;
  }

  for (int i=0; i<N; i++) {
    counter[A[i]-1]++;
  }

  for (int K=1; K<=N; K++) {
    priority_queue<pair<int,int>> pq;

    for (int i=0; i<N; i++) {
      if (counter[i])
        pq.push({counter[i], i});
    }

    int calc = 0;
    while((int)pq.size() >= K) {
      vector<pair<int,int>> vec;

      for (int i=0; i<K; i++) {
        auto p = pq.top(); pq.pop();

        p.first--;

        if (p.first)
          vec.push_back(p);
      }

      for (auto p : vec)
        pq.push(p);
      calc++;
    }

    ans.push_back(calc);
  }

  return ans;
}

vector<int> solve(int N) {
  vector<int> ans;

  for (int i=0; i<=N; i++) {
    counter[i] = 0;
    num[i] = 0;
  }

  for (int i=0; i<N; i++) {
    counter[A[i]-1]++;
  }

  int sum = N;
  for (int i=0; i<N; i++) {
    num[counter[i]]++;
  }

  int cc = 0;
  int t = N; //各
  for (int i=1; i<=N; i++) {
    while (t > sum / i) {
      cc += num[t];
      sum -= cc;
      t--;
    }

    ans.push_back(sum / i);
  }

  return ans;
}

int main(){
  int N;

  scanf("%d", &N);

  while(1) {
    for (int i=0; i<N; i++) {
      scanf("%d", A+i);
      //A[i] = rand() % N + 1;
    }
    auto v2 = solve(N);

    for (int i=0; i<N; i++) {
      cout << v2[i] << endl;
    }

    break;
    auto v1 = naive(N);

    if (v1 != v2) {
      for (int i=0; i<N; i++) {
        printf("%d ", A[i]);
      }
      puts("");
      debug(v2);
      debug(v1);
      exit(1);
    }
  }


  return 0;
}
