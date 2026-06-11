#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  
  S += 'R';
  
  vector<int> mojicount, RL;
  int count = 1;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == S[i+1]) {
      count++;
    } else {
      mojicount.push_back(count);
      count = 1;
    }
    
    if (S[i] == 'R' && S[i+1] == 'L') {
      RL.push_back(i);
    }
  }
  
  mojicount.pop_back();
  
  vector<pair<int, int>> child;
  for (int i = 0; i < mojicount.size(); i += 2) {
    int a = mojicount[i], b = mojicount[i+1];
    int left = (a + 1) / 2  + (b / 2);
    int right = a / 2 + (b + 1) / 2;
    
    child.push_back({left, right});


  }
  
  
  vector<int> ans(N, 0);
  
  for (int i = 0; i < child.size(); i++) {
    pair<int,int> p = child[i];
    
    int ind = RL[i];
    ans[ind] = p.first, ans[ind+1] = p.second;
  }
  
  
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  
  cout << endl;
  

       
        
  
}