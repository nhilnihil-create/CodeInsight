#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  int P[n];
  int cnt = 0;
  int min = INF;
  rep(i,n) {
    cin >> P[i];
    if(P[i]<=min){
      cnt++;
      min = P[i];
    }
  }
  cout << cnt <<endl;

}
