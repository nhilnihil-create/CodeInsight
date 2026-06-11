#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<pair<int64_t,char>> deli(a+b+c);
  for(int64_t i = 0; i < (a+b+c); i++){
    int d; cin >> d;
    char dc;
    if(i < a)
      dc = 'r';
    else if (i < (a+b))
      dc = 'g';
    else
      dc = 'w';
    deli[i] = make_pair(d, dc);
  }
  sort(deli.begin(), deli.end());
  reverse(deli.begin(), deli.end());
  
  int64_t sum = 0, cnt_r = 0, cnt_g = 0, cnt = 0;
  
  for(int64_t i = 0; i < (a+b+c); i++){
    char color = deli[i].second;
    if(color == 'r' && cnt_r == x)
      continue;
    if(color == 'g' && cnt_g == y)
      continue;
    
    sum += deli[i].first;
    cnt++;
    
    if(color == 'r')
      cnt_r++;
    if(color == 'g')
      cnt_g++;
    
    if(cnt == (x+y))
      break;
  }
  
  cout << sum << endl;
  
  return 0;
}