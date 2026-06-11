#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int x;
  cin >> x;
  vector<int> kyu={400,600,800,1000,1200,1400,1600,1800,2000};
  int ans = 0;
  rep(i,9){
    for(int j=kyu[i];j<kyu[i+1];j++){
      //cout << j << ",";
      if(j <= x) ans = i;
    }
  }
  cout << 8-ans << endl;
}