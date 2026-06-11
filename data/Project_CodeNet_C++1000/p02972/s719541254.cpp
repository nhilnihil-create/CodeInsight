#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;


int main(){
  int n;
  cin >> n;
  vector<int> a(n+1);
  rep(i,n) cin >> a[i+1];

  vector<int> b(n+1,0);
  int m = 0;
  for(int i = n; i >= 1; i--){
    int sum = 0;
    for(int j = 2*i; j <= n; j += i) sum ^= b[j];
    if(b[i] != sum^a[i]) m++;
      b[i] = sum^a[i];
  }

  cout << m << endl;
  for(int i = 1; i <=n; i++){
    if(b[i] == 1) cout << i << " ";
  }
  cout << endl;
}
