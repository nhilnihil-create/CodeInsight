#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  int x,y,a,b,c;
  cin >> x >> y >> a >> b >> c;
  const int max_n = 1e5;
  vector<pair<int, char>> apple;
  for(int i = 0; i < a+b+c; i++){
    int p;
    cin >> p;
    if(i < a) apple.push_back(make_pair(p, 'r'));
    else if(i >= a && i < a+b) apple.push_back(make_pair(p, 'g'));
    else apple.push_back(make_pair(p, 'x'));
  }

  sort(apple.begin(), apple.end());
  reverse(apple.begin(), apple.end());

  int cnt = 0;
  int red = 0;
  int green = 0;
  long long ans = 0;
  bool red_flag = 0;
  bool green_flag = 0;
  for(int i = 0; i < a + b + c; i++){
    if(cnt >= x + y) break;

    if(red >= x) red_flag = 1;
    if(green >= y) green_flag = 1;

    if(red_flag == 1 && apple[i].second == 'r') continue;
    if(green_flag == 1 && apple[i].second == 'g') continue;

    if(apple[i].second == 'r') red ++;
    if(apple[i].second == 'g') green ++;
    cnt ++;
    ans += apple[i].first;
  }
  cout << ans << endl;


  return 0;
}