#include <iostream>
#include <algorithm>
#include <vector>
  

using namespace std;
int main() {
  int a;
  cin >> a;
  int b[a];
  for(int i = 0;i<a;i++)cin >> b[i];
  int ans = 0;
  for(int i = 0;i<a-2;i++){
    if(b[i]>b[i+1]&&b[i+2]<b[i+1])ans++;
    if(b[i]<b[i+1]&&b[i+2]>b[i+1])ans++;
  }
  cout << ans;
}