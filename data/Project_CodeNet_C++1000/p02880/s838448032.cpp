#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;

  for(int a = 1;a<=9;a++){
    for(int b = 1; b<=9;b++){
      if(n==a*b){
	cout << "Yes" << endl;
	return 0;
      }
    }
  }

  cout << "No" << endl;
  
  return 0;
}
