#include<bits/stdc++.h>
using namespace std;

int main() {
  int a, b, m;
  cin >> a >> b >> m;
  
  vector<int> aa(a);
  for(int i = 0; i < a; i++) {
    cin >> aa.at(i);
  }
  
  vector<int> bb(b);
  for(int i = 0; i < b; i++) {
    cin >> bb.at(i);
  }
  
  int min = 1000000;
  
  for(int i = 0; i < m; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    int temp = aa.at(x - 1) + bb.at(y - 1) - c;
    if(temp < min) {
      min = temp;
    }
  }

  sort(aa.begin(), aa.end());
  sort(bb.begin(), bb.end());
  
  int mm = aa.at(0) + bb.at(0);
  if(mm < min) {
    min = mm;
  }
  
  cout << min << endl;
}
