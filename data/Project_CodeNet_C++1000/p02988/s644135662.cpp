#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  int n;
  cin >> n;
  vi p(n);
  rep(i,n) cin >> p[i];
  int sum=0;
  for(int i=1;i<n-1;i++){
    if(p[i] < p[i-1] && p[i+1] < p[i]){
      sum++;
    }
    if(p[i] < p[i+1] && p[i-1] < p[i]){
      sum++;
    }
  }
   cout << sum << endl;
}
