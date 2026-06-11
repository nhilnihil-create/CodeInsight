#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const long long INF = 1LL << 60;

string we[3] = {"Sunny","Cloudy","Rainy"};
string s;

int main()
{
  cin >> s;
  rep(i,3)
  {
    if(s == we[i]) cout << we[(i+1)%3] << endl;
  }
}