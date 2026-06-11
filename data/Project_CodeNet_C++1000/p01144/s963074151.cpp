#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;

int main() {
  int N, M;
  while(cin >> N >> M && (N|M)) {
    P ps[N];
    for(int i=0; i<N; i++) {
      cin >> ps[i].second >> ps[i].first;
      ps[i].first = -ps[i].first;
    }

    sort(ps, ps+N);
    for(int i=0; i<N; i++) {
      ps[i].first = -ps[i].first;
    }
    
    int psum = 0;
    for(int i=0; i<N; i++) {
      if(M>ps[i].second) {
	M -= ps[i].second;
      }
      else {
	psum += -M*ps[i].first; M = 0;
	psum += ps[i].first*ps[i].second;
      }
    }
    
    cout << psum<< endl;
  }
  
  return 0;
}