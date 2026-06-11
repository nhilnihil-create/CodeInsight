#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(x) cout << fixed << setprecision(x);
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
 
 
int main(){
  ll H1,M1,H2,M2,K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  long long ans = H2*60+M2-(H1*60+M1);
  cout << H2*60+M2-K- (H1*60+M1) << endl;
}