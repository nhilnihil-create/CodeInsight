#include <bits/stdc++.h>
using namespace std;

int main(){

  int N,M,Q;
  cin >> N >> M >> Q;
  vector<int> a(Q);
  vector<int> b(Q);
  vector<int> c(Q);
  vector<int> d(Q);

  for(int i = 0; i < Q; i++){
    cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
  }

  int n = N+M-1;
  int max = 0;

      for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
      if(S.size() == N){
        for(int i = 0; i < N; i++){
          S.at(i) -= i;
        }

        int point = 0;

        for(int i = 0; i < Q; i++){
          if(S.at(b.at(i)-1) - S.at(a.at(i)-1) == c.at(i)) point += d.at(i);
        }

        if (point > max) max = point;
      }
        
      }

      cout << max << endl;
}
