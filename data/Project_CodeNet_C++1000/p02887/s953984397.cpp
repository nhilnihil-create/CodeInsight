#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; i++)

const double PI=3.141592653589793;
const ll MX = 1e18;


int main()
{
  string S;
  int N;
  cin >> N >> S;
  int ds = 0;
  rep(i, S.size() - 1)
  {
    if(S[i]==S[i+1]){
      ds++;
    }
  }

  cout << S.size() - ds << endl;

  return 0;
}
