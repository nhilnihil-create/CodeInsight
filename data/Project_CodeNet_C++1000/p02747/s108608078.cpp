#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e18;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

int main(){
  string s;
  cin >> s;

  if(s =="hi") {
    cout << "Yes" << endl; return 0;
  }

  if(s =="hihi") {
    cout << "Yes" << endl; return 0;
  }

  if(s =="hihihi") {
    cout << "Yes" << endl; return 0;
  }
  
  if(s =="hihihihi") {
    cout << "Yes" << endl; return 0;
  }

  if(s =="hihihihihi") {
    cout << "Yes" << endl; return 0;
  }

  cout << "No" << endl;
  return 0;
}
