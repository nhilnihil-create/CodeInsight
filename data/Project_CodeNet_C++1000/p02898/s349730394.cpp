#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  int n, k, cnt=0;
  cin >> n >> k;
  rep(i, n){
    int h;
    cin >> h;
    if(h>=k)cnt++;
  }

  cout << cnt << endl;

  return 0;
}