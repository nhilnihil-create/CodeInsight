#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int h, w;
  int n;
  cin >> h >> w;
  cin >> n;
  int s = max(h, w);
  cout << (n + s - 1) / s << endl;
}