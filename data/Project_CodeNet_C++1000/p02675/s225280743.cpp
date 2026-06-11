#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair

int main() {
  int n; cin>>n;
  n%=10;
  if(n==3) cout<<"bon\n";
  else if(n==0||n==1||n==6||n==8) cout<<"pon\n";
  else cout<<"hon\n";
}
