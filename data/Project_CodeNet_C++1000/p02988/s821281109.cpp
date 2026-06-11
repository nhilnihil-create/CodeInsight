#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> s(n);
  int i;
  int cnt = 0;
  for(i=0;i<n;i++) cin >> s[i];
  for(i=1;i<n-1;i++){
    if((s[i-1]<s[i]&&s[i]<s[i+1])||(s[i-1]>s[i]&&s[i]>s[i+1])) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}