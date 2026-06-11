#include <bits/stdc++.h>
using namespace std;

#define ll long long 



int main() {
  int N;
  cin >> N;
  
  vector<int> P(N), Q(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> Q[i];
  }
  
  int perm[N];
  for (int i = 1; i <= N; i++) {
    perm[i-1] = i;
  }
  
  int a, b;
  int count = 0;
  do {
    count++;
    bool condA = true, condB = true;
    // Pがpermに一致しているか
    for (int i = 0; i < N; i++) {
      if (P[i] != perm[i]) {
        condA = false;
        break;
      }
    }
    
    if (condA) a = count;
    
    // Qがpermに一致しているか
    for (int i = 0; i < N; i++) {
      if (Q[i] != perm[i]) {
        condB = false;
        break;
      }
    }
    
    if (condB) b = count;
    
    
  } while(next_permutation(perm, perm+N));
 


  cout << abs(b-a) << endl;
              
}

