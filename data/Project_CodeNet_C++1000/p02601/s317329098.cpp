#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define all(vec) vec.begin(),vec.end()
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  rep(i,K){
    if(A>=B) B *=2;
    else if (B>=C) C*=2;
  }
  if (A < B && B < C) cout << "Yes" << endl;
  else cout << "No" << endl;
  
return 0;
}
