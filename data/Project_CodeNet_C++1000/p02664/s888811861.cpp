#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
string t;
cin >> t;
rep(i,t.size()){
  if(t.at(i) == '?') t.at(i) = 'D';
}
cout << t << endl;
}
