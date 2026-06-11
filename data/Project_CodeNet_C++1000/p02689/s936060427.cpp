#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, start, end) for (int i = (start); i <= (int)(end); i++)

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> height(n);
  vector<int> cond(n,1);
  rep(i,n){
    int h;
    cin >> h;
    height.at(i) = h;
  }

  rep(i,m){
    int a,b;
    cin >> a >> b;
    if (height.at(a-1) >= height.at(b-1)) cond.at(b-1) = 0;
    if (height.at(b-1) >= height.at(a-1)) cond.at(a-1) = 0;
  }

  int answer = 0;
  rep(i,n) answer += cond.at(i);

  cout << answer << endl;

}
