#include <iostream>
#include <algorithm>

using namespace std;

int s[2];
int data[2][1501];
int cnt[2][1500001];

main(){
  while(cin >> s[0] >> s[1] && (s[0]|s[1])){
    data[0][0] = data[1][0] = 0;
    for(int j=0;j<2;j++){
      for(int i=1;i<=s[j];i++){
        int in;
        cin >> in;
        data[j][i] = data[j][i-1] + in;
      }
    }
    fill(cnt[0], cnt[2], 0);
    for(int k=0;k<2;k++){
      for(int i=0;i<=s[k];i++){
        for(int j=i+1;j<=s[k];j++){
          cnt[k][data[k][j]-data[k][i]]++;
        }
      }
    }
    int ans = 0;
    for(int i=1;i<=1500000;i++){
      ans += cnt[0][i] * cnt[1][i];
    }
    cout << ans << endl;
  }
  return 0;
}