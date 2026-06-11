#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>

const ll INF = pow(10, 9) + 7;

int main() {
  string s;
  cin >> s;
  if(s=="Sunny") cout << "Cloudy" << endl;
  if(s=="Cloudy") cout << "Rainy" << endl;
  if(s=="Rainy") cout << "Sunny" << endl;
}