#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  string s;
  cin >> s;
  if(s=="Sunny")cout << "Cloudy" << endl;
  if(s=="Cloudy")cout << "Rainy" << endl;
  if(s=="Rainy")cout << "Sunny" << endl;
}