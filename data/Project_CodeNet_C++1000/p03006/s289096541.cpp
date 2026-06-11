#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<pair<int,int>> ball(N);
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    
    ball[i] = {x, y};
  }
  
  int maxcount = 0;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      
      int p = ball[i].first - ball[j].first;
      int q = ball[i].second - ball[j].second;
      
      int count = 0;
     
      for (int k = 0; k < N; k++) {
        for (int l = 0; l < N; l++) {
          if (k == l) continue;
          
          if (ball[k].first - ball[l].first == p 
             && ball[k].second - ball[l].second == q) count++;
        }
      }
      
      maxcount = max(maxcount, count);
       
    }
  }
  
  cout << N - maxcount << endl;
}