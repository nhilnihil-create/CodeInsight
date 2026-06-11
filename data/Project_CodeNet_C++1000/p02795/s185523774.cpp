#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intput(i) cout << i << endl
#define ll long long
#define stringput(s) cout << (string)(s) << endl

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  int a = max(H, W);
  int i = 0;
  int j = 0;
  while(i < N){
    i += a;
    j++;
  }
  cout << j << endl;
}