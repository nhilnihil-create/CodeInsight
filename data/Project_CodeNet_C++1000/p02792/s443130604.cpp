#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int nums[11][11];
int main(){
  int n;
  cin >> n;

  for (int i = 1;i <= n;i++){
    string s;
    s = to_string(i);
    int top,last;
    top = stoi(s.substr(0,1));
    last = stoi(s.substr(s.size()-1,1));
    nums[top][last]++;
  }
  ll ans = 0LL;
  for (int i = 1;i <= 9;i++){
    for (int j = 1; j <= 9;j++){
      ans += nums[i][j]*nums[j][i];
    }
  }
  cout << ans << endl;
   
  return 0; 
}

