#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  int P[N]; int Q[N];
  FOR(i,0,N) cin >> P[i];
  FOR(i,0,N) cin >> Q[i];
  
  
  iota(v.begin(), v.end(), 1);
  int count1 = 1;
  int Pcount;
  do{
    bool flag1 = true;
    FOR(i,0,N) {
      if (v[i] != P[i]) flag1 = false;
    }
    if(flag1) Pcount = count1;
    count1++;
  }while(next_permutation(v.begin(), v.end()));

  iota(v.begin(), v.end(), 1);
  int count2 = 1;
  int Qcount;
  do{
    bool flag2 = true;
    FOR(i,0,N) {
      if (v[i] != Q[i]) flag2 = false;
    }
    if(flag2) Qcount = count2;
    count2++;
  }while(next_permutation(v.begin(), v.end()));  
  
  cout << abs(Pcount - Qcount) << endl;
  
  return 0;
}