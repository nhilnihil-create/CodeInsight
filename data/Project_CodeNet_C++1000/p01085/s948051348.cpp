#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> answer;
  while(1){
    int m,n_min,n_max,gap_max = 0,ans;
    cin >> m >> n_min >> n_max;
    if(!m)break;
    vector<int> point(m);
    for(int i = 0;i < m;i++)cin >> point[i];
    sort(point.begin(),point.end());
    for(int i = m-n_max;i <= m-n_min;i++){
      if(point[i] - point[i-1] > gap_max){
        ans = m-i;
        gap_max = point[i] - point[i-1];
      }
    }
    answer.push_back(ans);
  }
  for(int i = 0;i < answer.size();i++)cout << answer[i] << endl;
}

