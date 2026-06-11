#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;
using ping = pair<ll, ll>;

int main() {
  string N;
  cin >> N;
  if(N[N.size() - 1]=='3'){
    cout << "bon" << endl;
  }
  else if(N[N.size() - 1]=='0' || N[N.size() - 1]=='1' || N[N.size() - 1]=='6' || N[N.size() -1] == '8'){
    cout << "pon" << endl;
  }
  else{
      cout << "hon" << endl;
  }
  return 0;
}