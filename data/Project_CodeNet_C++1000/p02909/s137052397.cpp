#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)
const ll mod = 1e9+7;


int main(){
  string s;
  cin >> s;
  if (s =="Sunny") cout << "Cloudy" << endl;
  else if (s == "Cloudy") cout << "Rainy" << endl;
  else cout << "Sunny" << endl;


  return 0;
}