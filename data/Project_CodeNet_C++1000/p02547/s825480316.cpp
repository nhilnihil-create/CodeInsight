#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    if(a == b) cnt++;
    else cnt = 0;
    if(cnt == 3){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}