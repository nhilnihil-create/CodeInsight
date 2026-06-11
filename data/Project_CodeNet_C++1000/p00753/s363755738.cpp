#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
const int inf = numeric_limits<int>::max();
const ll mod = 1e9 + 7;

int isp[300000];

void solve(int n){
  int cnt = 0;
  for(int i = n+1;i <= 2*n;++i){
    if(isp[i])++cnt;
  }
  cout << cnt << endl;
}

int main(void){
  fill(isp,isp+300000,1);
  isp[1] = 0;
  for(int i = 2;i*i < 300000;++i){
    if(isp[i]){
      for(int j = i*i;j < 300000;j += i){
        isp[j] = 0;
      }
    }
  }
  int n;
  while(cin >> n,n)solve(n);
  return 0;
}